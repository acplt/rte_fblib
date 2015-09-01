/*
*	Copyright (C) 2015
*	Chair of Process Control Engineering,
*	Aachen University of Technology.
*	All rights reserved.
*
*	Redistribution and use in source and binary forms, with or without
*	modification, are permitted provided that the following conditions
*	are met:
*	1. Redistributions of source code must retain the above copyright
*	   notice, this list of conditions and the following disclaimer.
*	2. Redistributions in binary form must print or display the above
*	   copyright notice either during startup or must have a means for
*	   the user to view the copyright notice.
*	3. Redistributions in binary form must reproduce the above copyright
*	   notice, this list of conditions and the following disclaimer in
*		the documentation and/or other materials provided with the
*		distribution.
*	4. Neither the name of the Chair of Process Control Engineering nor
*		the name of the Aachen University of Technology may be used to
*		endorse or promote products derived from this software without
*		specific prior written permission.
*
*	THIS SOFTWARE IS PROVIDED BY THE CHAIR OF PROCESS CONTROL ENGINEERING
*	``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE CHAIR OF
*	PROCESS CONTROL ENGINEERING BE LIABLE FOR ANY DIRECT, INDIRECT,
*	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
*	OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
*	AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
*	WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*	POSSIBILITY OF SUCH DAMAGE.
***********************************************************************/
#ifndef OV_COMPILE_LIBRARY_iec62541fb
#define OV_COMPILE_LIBRARY_iec62541fb
#endif


#include "iec62541fb.h"
#include "libov/ov_macros.h"

OV_DLLFNCEXPORT void iec62541fb_Connect_startup(
		OV_INSTPTR_ov_object 	pobj
) {
	/*
	 *   local variables
	 */
	OV_INSTPTR_iec62541fb_Connect pinst = Ov_StaticPtrCast(iec62541fb_Connect, pobj);

	/* do what the base class does first */
	fb_functionblock_startup(pobj);

	pinst->v_ConnectionHdl = 0;
	pinst->v_Client = NULL;

	return;
}

OV_DLLFNCEXPORT void iec62541fb_Connect_shutdown(
		OV_INSTPTR_ov_object 	pobj
) {
	/*
	 *   local variables
	 */
	OV_INSTPTR_iec62541fb_Connect pinst = Ov_StaticPtrCast(iec62541fb_Connect, pobj);

	if(pinst->v_Client != NULL){
		UA_Client_disconnect(pinst->v_Client);
		UA_Client_delete(pinst->v_Client);
	}
	pinst->v_Client = NULL;

	/* set the object's state to "shut down" */
	fb_functionblock_shutdown(pobj);

	return;
}


OV_DLLFNCEXPORT OV_RESULT iec62541fb_Connect_Execute_set(
		OV_INSTPTR_iec62541fb_Connect          pinst,
		const OV_BOOL  value
) {
	UA_StatusCode retval = UA_STATUSCODE_GOOD;

	if(value == FALSE || pinst->v_Execute == TRUE){
		//only react on the rising edge
		pinst->v_Execute = value;
		return OV_ERR_OK;
	}

	pinst->v_Client = UA_Client_new(UA_ClientConfig_standard, NULL);
	//todo use TCPchannel which is a part of us
	retval = UA_Client_connect(pinst->v_Client, ClientNetworkLayerTCP_connect, pinst->v_ServerEndpointUrl);
	if(retval != UA_STATUSCODE_GOOD) {
		if(pinst->v_Client != NULL){
			UA_Client_delete(pinst->v_Client);
		}
		pinst->v_Client = NULL;
		pinst->v_Error = TRUE;
		pinst->v_ErrorID = 1;	//todo
		pinst->v_Done = FALSE;
		return OV_ERR_BADVALUE;
	}
	pinst->v_ConnectionHdl = pinst->v_idL;
	pinst->v_Done = TRUE;
	pinst->v_Error = FALSE;
	pinst->v_ErrorID = 0;

	pinst->v_Execute = value;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT iec62541fb_Connect_ServerEndpointUrl_set(
		OV_INSTPTR_iec62541fb_Connect          pinst,
		const OV_STRING  value
) {
	pinst->v_Done = FALSE;
	pinst->v_Execute = FALSE;
	return ov_string_setvalue(&pinst->v_ServerEndpointUrl,value);
}

OV_DLLFNCEXPORT void iec62541fb_Connect_typemethod(
		OV_INSTPTR_fb_functionblock	pfb,
		OV_TIME						*pltc
) {
	/*
	 *   local variables
	 */
	//OV_INSTPTR_iec62541fb_Connect pinst = Ov_StaticPtrCast(iec62541fb_Connect, pfb);

	/* fixme does not compile...
	if(pinst->v_Client.scExpiresAt - UA_DateTime_now() <= pinst->v_Client.config.timeToRenewSecureChannel * 10000 ){
		UA_Client_renewSecureChannel(pinst->v_Client);
	}
	*/

	return;
}


