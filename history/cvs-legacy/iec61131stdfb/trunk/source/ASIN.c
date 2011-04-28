/*
*	Copyright (C) 2010
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
*/
/******************************************************************************
*
*   FILE
*   ----
*   ASIN.c
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

#define OV_DEBUG

#include "iec61131stdfb.h"
#include "stdfb_macros.h"
#include "libov/ov_macros.h"
#include "libov/ov_logfile.h"
#include "helper.h"


#include <math.h>


OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ASIN_IN_set(
    OV_INSTPTR_iec61131stdfb_ASIN          pobj,
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

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_ASIN_OUT_get(
    OV_INSTPTR_iec61131stdfb_ASIN          pobj
) {
    return &pobj->v_OUT;
}

OV_DLLFNCEXPORT void iec61131stdfb_ASIN_shutdown(OV_INSTPTR_ov_object pobj) {

	OV_INSTPTR_iec61131stdfb_ASIN pinst = Ov_StaticPtrCast(iec61131stdfb_ASIN, pobj);
	
	iec61131stdfb_freeVec(&pinst->v_IN);
	iec61131stdfb_freeVec(&pinst->v_OUT);
	ov_object_shutdown(pobj);
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ASIN_constructor(OV_INSTPTR_ov_object pobj) {

	OV_RESULT res;
	OV_INSTPTR_iec61131stdfb_ASIN pinst = Ov_StaticPtrCast(iec61131stdfb_ASIN, pobj);
	
	res = ov_object_constructor(pobj);
	
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

OV_DLLFNCEXPORT void iec61131stdfb_ASIN_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	
	unsigned int i;
	OV_BOOL STDFB_bad_operation = FALSE;
	
    OV_INSTPTR_iec61131stdfb_ASIN pinst = Ov_StaticPtrCast(iec61131stdfb_ASIN, pfb);
	
	iec61131stdfb_freeVec(&pinst->v_OUT);
	
	if(!(pinst->v_IN.value.vartype & OV_VT_ISVECTOR))
		{
			switch(pinst->v_IN.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					ov_logfile_warning("%s: arc sine of integer value -> not reasonable, setting out to single to prevent data loss", pinst->v_identifier);
					if((pinst->v_IN.value.valueunion.val_int >= -1)
						&& (pinst->v_IN.value.valueunion.val_int <= 1))
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_int);
					else
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_int);
						ov_logfile_error("%s: trying to calculate arc sine of value larger than 1 or smaller than -1", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
				break;
				
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					ov_logfile_warning("%s: arc sine of integer value -> not reasonable, setting out to single to prevent data loss", pinst->v_identifier);
					if(pinst->v_IN.value.valueunion.val_uint <= 1)
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_uint);
					else
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_uint);
						ov_logfile_error("%s: trying to calculate arc sine of value larger than 1", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
				break;
				
				case OV_VT_SINGLE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					if((pinst->v_IN.value.valueunion.val_single >= -1)
						&& (pinst->v_IN.value.valueunion.val_single <= 1))
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_single);
					else
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_single);
						ov_logfile_error("%s: trying to calculate arc sine of value larger than 1 or smaller than -1", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
				break;
				
				case OV_VT_DOUBLE:
					pinst->v_OUT.value.vartype = OV_VT_DOUBLE;
					if((pinst->v_IN.value.valueunion.val_double >= -1)
						&& (pinst->v_IN.value.valueunion.val_double <= 1))
						pinst->v_OUT.value.valueunion.val_double = asin(pinst->v_IN.value.valueunion.val_double);
					else
					{
						pinst->v_OUT.value.valueunion.val_double = asin(pinst->v_IN.value.valueunion.val_double);
						ov_logfile_error("%s: trying to calculate arc sine of value larger than 1 or smaller than -1", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
				
				break;

				case OV_VT_BYTE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					ov_logfile_warning("%s: bitstring given, treating as unsigned integer, setting out to single to prevent data loss", pinst->v_identifier);
					if(pinst->v_IN.value.valueunion.val_byte <= 1)
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_byte);
					else
					{
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) asin(pinst->v_IN.value.valueunion.val_byte);
						ov_logfile_error("%s: trying to calculate arc sine of value larger than 1", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
					
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
					STDFB_VEC_ASIN_I(INT, int);
				break;
		
				case OV_VT_UINT_VEC:
					STDFB_VEC_ASIN_UI(UINT, uint);
				break;
			
				case OV_VT_SINGLE_VEC:
					STDFB_VEC_ASIN_R(SINGLE, single);
				break;
		
				case OV_VT_DOUBLE_VEC:
					STDFB_VEC_ASIN_R(DOUBLE, double);
				break;

				case OV_VT_BYTE_VEC:
					ov_logfile_warning("%s: bitstring given, treating as unsigned integer", pinst->v_identifier);
					STDFB_VEC_ASIN_UI(BYTE, byte);
				break;
			
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: operation cannot be done on given datatype", pinst->v_identifier);
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

