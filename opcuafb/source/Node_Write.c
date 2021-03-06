/*
*   Copyright (C) 2015
*   Chair of Process Control Engineering,
*   D-52056 Aachen, Germany.
*   All rights reserved.
*
*
*   This file is part of the ACPLT/OV Package 
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
***********************************************************************/

#ifndef OV_COMPILE_LIBRARY_opcuafb
#define OV_COMPILE_LIBRARY_opcuafb
#endif


#include "opcuafb.h"
#include "ov_macros.h"
#include "fb_namedef.h"
#include "errno.h"

OV_DLLFNCEXPORT OV_RESULT opcuafb_Write_Variable_set(
		OV_INSTPTR_opcuafb_Write          pobj,
		const OV_ANY*  value
) {
	switch (value->value.vartype & OV_VT_KSMASK){
	case OV_VT_INT:
	case OV_VT_UINT:
	case OV_VT_SINGLE:
	case OV_VT_DOUBLE:
	case OV_VT_STRING:
	case OV_VT_TIME:
		//white list
		break;
	default:
		return OV_ERR_BADTYPE;
		break;
	}

	return ov_variable_setanyvalue(&pobj->v_Variable, value);
}

OV_DLLFNCEXPORT OV_RESULT opcuafb_Write_Execute_set(
		OV_INSTPTR_opcuafb_Write          pinst,
		const OV_BOOL  value
) {
	OV_INSTPTR_opcuafb_Connect pConnect = NULL;
	OV_INSTPTR_opcuafb_NodeGetHandle pNodeGetHandle = NULL;
	UA_WriteRequest WriteRequest;
	UA_WriteResponse WriteResponse;
	UA_String tempString;
	UA_DateTime *tempTime;
	char *endPtr = NULL;
	unsigned long int tempulong = 0;

	if(value == FALSE || pinst->v_Execute == TRUE){
		//only react on the rising edge
		pinst->v_Execute = value;
		return OV_ERR_OK;
	}

	pConnect = Ov_DynamicPtrCast(opcuafb_Connect, fb_connection_getFirstConnectedObject(Ov_PtrUpCast(fb_object, pinst), FALSE, TRUE, "ConnectionHdl"));
	if(pConnect == NULL){
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1; //todo
		return OV_ERR_BADVALUE;
	}
	if(pConnect->v_ConnectionHdl == 0){
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1; //todo
		return OV_ERR_BADVALUE;
	}
	if(pConnect->v_Client == NULL){
		//internal error
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1; //todo
		return OV_ERR_BADVALUE;
	}

	pNodeGetHandle = Ov_DynamicPtrCast(opcuafb_NodeGetHandle, fb_connection_getFirstConnectedObject(Ov_PtrUpCast(fb_object, pinst), FALSE, TRUE, "NodeHdl"));
	if(pNodeGetHandle == NULL){
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1; //todo
		return OV_ERR_BADVALUE;
	}
	if(pNodeGetHandle->v_NodeHdl == 0){
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1; //todo
		return OV_ERR_BADVALUE;
	}

	UA_WriteRequest_init(&WriteRequest);
	WriteRequest.nodesToWrite = UA_WriteValue_new();
	WriteRequest.nodesToWriteSize = 1;
	WriteRequest.nodesToWrite[0].attributeId = UA_ATTRIBUTEID_VALUE;
	WriteRequest.nodesToWrite[0].value.hasValue = UA_TRUE;
	if(pNodeGetHandle->v_NodeID.IdentifierType == UA_IDTYPE_STRING){
		WriteRequest.nodesToWrite[0].nodeId = UA_NODEID_STRING_ALLOC(pNodeGetHandle->v_NodeID.NamespaceIndex, pNodeGetHandle->v_NodeID.Identifier);
	}else if(pNodeGetHandle->v_NodeID.IdentifierType == UA_IDTYPE_NUMERIC){
		tempulong = strtoul(pNodeGetHandle->v_NodeID.Identifier, &endPtr, 10);
		if (ERANGE != errno &&
			tempulong < UINT16_MAX &&
			endPtr != pNodeGetHandle->v_NodeID.Identifier)
		{
			WriteRequest.nodesToWrite[0].nodeId = UA_NODEID_NUMERIC(pNodeGetHandle->v_NodeID.NamespaceIndex, (UA_UInt16)tempulong);
		}
		WriteRequest.nodesToWrite[0].nodeId = UA_NODEID_NUMERIC(pNodeGetHandle->v_NodeID.NamespaceIndex, atoi(pNodeGetHandle->v_NodeID.Identifier));
//	}else if(pNodeGetHandle->v_NodeID.IdentifierType == UA_IDTYPE_GUID){
		//todo
		//WriteRequest.nodesToWrite[0].nodeId = UA_NODEID_GUID(pNodeGetHandle->v_NodeID.NamespaceIndex, pNodeGetHandle->v_NodeID.Identifier);
	}else{
		UA_WriteRequest_deleteMembers(&WriteRequest);
		return OV_ERR_BADVALUE;
	}


	switch (pinst->v_Variable.value.vartype & OV_VT_KSMASK){
	case OV_VT_INT:
		WriteRequest.nodesToWrite[0].value.value.type = &UA_TYPES[UA_TYPES_INT32];
		WriteRequest.nodesToWrite[0].value.value.storageType = UA_VARIANT_DATA_NODELETE; //do not free the data on deletion
		WriteRequest.nodesToWrite[0].value.value.data = &pinst->v_Variable.value.valueunion.val_int;
		break;
	case OV_VT_UINT:
		WriteRequest.nodesToWrite[0].value.value.type = &UA_TYPES[UA_TYPES_UINT32];
		WriteRequest.nodesToWrite[0].value.value.storageType = UA_VARIANT_DATA_NODELETE; //do not free the data on deletion
		WriteRequest.nodesToWrite[0].value.value.data = &pinst->v_Variable.value.valueunion.val_uint;
		break;
	case OV_VT_SINGLE:
		WriteRequest.nodesToWrite[0].value.value.type = &UA_TYPES[UA_TYPES_FLOAT];
		WriteRequest.nodesToWrite[0].value.value.storageType = UA_VARIANT_DATA_NODELETE; //do not free the data on deletion
		WriteRequest.nodesToWrite[0].value.value.data = &pinst->v_Variable.value.valueunion.val_single;
		break;
	case OV_VT_DOUBLE:
		WriteRequest.nodesToWrite[0].value.value.type = &UA_TYPES[UA_TYPES_DOUBLE];
		WriteRequest.nodesToWrite[0].value.value.storageType = UA_VARIANT_DATA_NODELETE; //do not free the data on deletion
		WriteRequest.nodesToWrite[0].value.value.data = &pinst->v_Variable.value.valueunion.val_double;
		break;
	case OV_VT_STRING:
		WriteRequest.nodesToWrite[0].value.value.type = &UA_TYPES[UA_TYPES_STRING];
		WriteRequest.nodesToWrite[0].value.value.storageType = UA_VARIANT_DATA; //free the data on deletion
		WriteRequest.nodesToWrite[0].value.value.data = UA_String_new();
		tempString = UA_String_fromChars(pinst->v_Variable.value.valueunion.val_string);
		WriteRequest.nodesToWrite[0].value.value.data = &tempString;
		break;
	case OV_VT_TIME:
		WriteRequest.nodesToWrite[0].value.value.type = &UA_TYPES[UA_TYPES_DATETIME];
		WriteRequest.nodesToWrite[0].value.value.storageType = UA_VARIANT_DATA; //free the data on deletion
		tempTime = UA_DateTime_new();
		if(tempTime){
			*tempTime = ov_ovTimeTo1601nsTime(pinst->v_Variable.value.valueunion.val_time);
			WriteRequest.nodesToWrite[0].value.value.data = tempTime;
		}else{
			pinst->v_Error = TRUE;
			pinst->v_ErrorID = 1; // todo
		}
		break;
	default:
		break;
	}

	WriteResponse = UA_Client_Service_write(pConnect->v_Client, WriteRequest);
	if(WriteResponse.responseHeader.serviceResult != UA_STATUSCODE_GOOD){
		pinst->v_Error = FALSE;
		pinst->v_ErrorID = 0;
	}else{
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1; // todo
	}
	UA_WriteResponse_deleteMembers(&WriteResponse);
	UA_WriteRequest_deleteMembers(&WriteRequest);

	pinst->v_Done = TRUE;
	pinst->v_Execute = value;
	return OV_ERR_OK;
}


OV_DLLFNCEXPORT OV_RESULT opcuafb_Write_ConnectionHdl_set(
		OV_INSTPTR_opcuafb_Write          pinst,
		const OV_UINT  value
) {
	if(value == 0){
		pinst->v_Done = TRUE;
	}else{
		if(pinst->v_ConnectionHdl == 0 && fb_connection_getFirstConnectedObject(Ov_PtrUpCast(fb_object, pinst), FALSE, TRUE, "Execute") == NULL){
			//we have a new connection and no connection on execute, so prepare for a new activation
			opcuafb_Write_Execute_set(pinst, FALSE);
		}
		pinst->v_Done = FALSE;
	}
	pinst->v_ConnectionHdl = value;
	pinst->v_Busy = FALSE;
	pinst->v_Error = FALSE;
	pinst->v_ErrorID = 0;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT opcuafb_Write_NodeHdl_set(
		OV_INSTPTR_opcuafb_Write          pinst,
		const OV_UINT  value
) {
	if(value == 0){
		pinst->v_Done = TRUE;
	}else{
		if(pinst->v_NodeHdl == 0 && fb_connection_getFirstConnectedObject(Ov_PtrUpCast(fb_object, pinst), FALSE, TRUE, "Execute") == NULL){
			//we have a new nodeID and no connection on execute, so prepare for a new activation
			opcuafb_Write_Execute_set(pinst, FALSE);
		}
		pinst->v_Done = FALSE;
	}
	pinst->v_Busy = FALSE;
	pinst->v_Error = FALSE;
	pinst->v_ErrorID = 0;
	pinst->v_NodeHdl = value;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT void opcuafb_Write_startup(
		OV_INSTPTR_ov_object 	pobj
) {
	/*
	 *   local variables
	 */
	//OV_INSTPTR_opcuafb_Write pinst = Ov_StaticPtrCast(opcuafb_Write, pobj);

	/* do what the base class does first */
	fb_functionblock_startup(pobj);

	/*
	pinst->v_NodeAddInfo.IndexRangeCount = 0;
	pinst->v_NodeAddInfo.AttributeId = 0;
	*/

	return;
}
