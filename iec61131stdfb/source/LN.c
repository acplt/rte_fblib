/*
*   Copyright (C) 2010
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
*/
/******************************************************************************
*
*   FILE
*   ----
*   LN.c
*
*   History
*   -------
*   2010-11-03   File created
*
*******************************************************************************
*
*   This file is generated by the 'fb_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_iec61131stdfb
#define OV_COMPILE_LIBRARY_iec61131stdfb
#endif

#include "iec61131stdfb.h"
#include "stdfb_macros.h"
#include "ov_macros.h"
#include "ov_logfile.h"
#include "helper.h"

#include <math.h>


OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_LN_IN_set(
    OV_INSTPTR_iec61131stdfb_LN          pobj,
    const OV_ANY*  value
) {
    if((value->value.vartype & OV_VT_KSMASK) == (pobj->v_IN.value.vartype & OV_VT_KSMASK))
		return ov_variable_setanyvalue(&pobj->v_IN, value);
	else
	{
		if (iec61131stdfb_isConnected (Ov_PtrUpCast (fb_functionblock, pobj)))
			return OV_ERR_NOACCESS;
		else
		{
			iec61131stdfb_freeVec(&pobj->v_IN);
			iec61131stdfb_freeVec(&pobj->v_OUT);
			switch(value->value.vartype & OV_VT_KSMASK)
			{
				case OV_VT_INT:
				case OV_VT_UINT:
				case OV_VT_BYTE:
				case OV_VT_SINGLE:
					pobj->v_OUT.value.vartype = OV_VT_SINGLE;
				return ov_variable_setanyvalue(&pobj->v_IN, value);
				
				case OV_VT_DOUBLE:
					pobj->v_OUT.value.vartype = OV_VT_DOUBLE;
				return ov_variable_setanyvalue(&pobj->v_IN, value);
				
				case OV_VT_INT_VEC:
				case OV_VT_UINT_VEC:
				case OV_VT_BYTE_VEC:
				case OV_VT_SINGLE_VEC:
					pobj->v_OUT.value.vartype = OV_VT_SINGLE_VEC;
				return ov_variable_setanyvalue(&pobj->v_IN, value);
				
				case OV_VT_DOUBLE_VEC:
					pobj->v_OUT.value.vartype = OV_VT_DOUBLE_VEC;
				return ov_variable_setanyvalue(&pobj->v_IN, value);
				
				default:
					return OV_ERR_BADPARAM;
			}
			return OV_ERR_GENERIC;
		}
	}
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_LN_OUT_get(
    OV_INSTPTR_iec61131stdfb_LN          pobj
) {
    return &pobj->v_OUT;
}


OV_DLLFNCEXPORT void iec61131stdfb_LN_destructor(OV_INSTPTR_ov_object pobj) {

	OV_INSTPTR_iec61131stdfb_LN pinst = Ov_StaticPtrCast(iec61131stdfb_LN, pobj);
	
	iec61131stdfb_freeVec(&pinst->v_IN);
	iec61131stdfb_freeVec(&pinst->v_OUT);
	fb_functionblock_destructor(pobj);
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_LN_constructor(OV_INSTPTR_ov_object pobj) {

	OV_RESULT res;
	OV_INSTPTR_iec61131stdfb_LN pinst = Ov_StaticPtrCast(iec61131stdfb_LN, pobj);
	
	res = fb_functionblock_constructor(pobj);
	
	if(Ov_OK(res))
	{
		pinst->v_IN.value.valueunion.val_double = 0;
		pinst->v_OUT.value.valueunion.val_double = 0;
		pinst->v_IN.value.vartype = OV_VT_SINGLE;
		pinst->v_OUT.value.vartype = OV_VT_SINGLE;
		return OV_ERR_OK;
	}
	else
		return res;
}

OV_DLLFNCEXPORT void iec61131stdfb_LN_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	unsigned int i;
	OV_BOOL STDFB_bad_operation = FALSE;
	
    OV_INSTPTR_iec61131stdfb_LN pinst = Ov_StaticPtrCast(iec61131stdfb_LN, pfb);
	STDFB_FREE_VEC(pinst->v_OUT);
	if(!(pinst->v_IN.value.vartype & OV_VT_ISVECTOR))
		{
			switch(pinst->v_IN.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					ov_logfile_warning("%s: input value is integer, output is set to single to prevent data loss", pinst->v_identifier);
					if(pinst->v_IN.value.valueunion.val_int <= 0)
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_int);
						STDFB_bad_operation = TRUE;
						ov_logfile_error("%s: trying to calculate the logarithm of 0 or a negative value", pinst->v_identifier);
						
					}
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_int);
				break;
				
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					ov_logfile_warning("%s: input value is unsigned integer, output is set to single to prevent data loss", pinst->v_identifier);
					if(pinst->v_IN.value.valueunion.val_uint == 0)
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_uint);
						STDFB_bad_operation = TRUE;
						ov_logfile_error("%s: trying to calculate the logarithm of 0", pinst->v_identifier);
						
					}
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_uint);
				break;
				
				case OV_VT_SINGLE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					if(pinst->v_IN.value.valueunion.val_single <= 0)
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_single);
						STDFB_bad_operation = TRUE;
						ov_logfile_error("%s: trying to calculate the logarithm of 0 or a negative value", pinst->v_identifier);
					}
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_single);
				break;
				
				case OV_VT_DOUBLE:
					pinst->v_OUT.value.vartype = OV_VT_DOUBLE;
					if(pinst->v_IN.value.valueunion.val_double <= 0)
					{
						pinst->v_OUT.value.valueunion.val_double = log(pinst->v_IN.value.valueunion.val_double);
						STDFB_bad_operation = TRUE;
						ov_logfile_error("%s: trying to calculate the logarithm of 0 or a negative value", pinst->v_identifier);
					}
					else
						pinst->v_OUT.value.valueunion.val_double = log(pinst->v_IN.value.valueunion.val_double);
				
				break;
				
				case OV_VT_BYTE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					ov_logfile_warning("%s: input value is byte, output is set to single to prevent data loss", pinst->v_identifier);
					if(pinst->v_IN.value.valueunion.val_byte == 0)
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_byte);
						STDFB_bad_operation = TRUE;
						ov_logfile_error("%s: trying to calculate the logarithm of 0", pinst->v_identifier);
					}
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) log(pinst->v_IN.value.valueunion.val_byte);
				break;

				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: operation cannot be done on given datatype", pinst->v_identifier);
					STDFB_bad_operation = TRUE;
				break;
			}
		}
		else
		{
			switch(pinst->v_IN.value.vartype & OV_VT_KSMASK)
			{
			
				case OV_VT_INT_VEC:
					STDFB_VEC_LN_I(INT, int);
				break;
			
				case OV_VT_UINT_VEC:
					STDFB_VEC_LN_I(UINT, uint);
				break;
				
				case OV_VT_SINGLE_VEC:
					STDFB_VEC_LN_R(SINGLE, single);
				break;
			
				case OV_VT_DOUBLE_VEC:
					STDFB_VEC_LN_R(DOUBLE, double);
				break;

				case OV_VT_BYTE_VEC:
					STDFB_VEC_LN_I(BYTE, byte);
				break;
			
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: ln of given datatypes senseless", pinst->v_identifier);
					STDFB_bad_operation = TRUE;
				break;
			}
		}
		
		/************** handling states ********************************/
		
	STDFB_STATE(IN);
	
	/***************** handling timestamps ************************/
	STDFB_TIMESTAMP(IN);
		
    return;
}

