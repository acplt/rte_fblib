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
*   AND.c
*
*   History
*   -------
*   2010-11-30   File created
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
#include "libov/ov_macros.h"
#include "libov/ov_logfile.h"

OV_BOOL 
iec61131stdfb_isConnected 
(OV_INSTPTR_fb_functionblock fb)
{
  if (Ov_GetFirstChild (fb_inputconnections, fb)) return TRUE;
  if (Ov_GetFirstChild (fb_outputconnections, fb)) return TRUE;
  return FALSE;
}

OV_RESULT
iec61131stdfb_AND_setType
(OV_INSTPTR_iec61131stdfb_AND pobj, OV_VAR_TYPE type)
{
  if (iec61131stdfb_isConnected (Ov_PtrUpCast (fb_functionblock, pobj)))
    return OV_ERR_NOACCESS;
  else
  {
    /* TODO: check if type is allowed */
    pobj->v_IN1.value.vartype = type;
    pobj->v_IN2.value.vartype = type;
    pobj->v_OUT.value.vartype = type;
    return OV_ERR_OK;
  }
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_AND_IN1_set(
    OV_INSTPTR_iec61131stdfb_AND          pobj,
    const OV_ANY*  value
) 
{
  if (value->value.vartype == pobj->v_IN1.value.vartype)
    return ov_variable_setanyvalue (&pobj->v_IN1, value);
  else
  {
    OV_RESULT res = iec61131stdfb_AND_setType (pobj, value->value.vartype); 
    if (Ov_OK (res))
      return ov_variable_setanyvalue (&pobj->v_IN1, value);
    else return res;
  }
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_AND_IN2_set(
    OV_INSTPTR_iec61131stdfb_AND          pobj,
    const OV_ANY*  value
) 
{
  if (value->value.vartype == pobj->v_IN2.value.vartype)
    return ov_variable_setanyvalue (&pobj->v_IN2, value);
  else
  {
    OV_RESULT res = iec61131stdfb_AND_setType (pobj, value->value.vartype); 
    if (Ov_OK (res))
      return ov_variable_setanyvalue (&pobj->v_IN2, value);
    else return res;
  }
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_AND_OUT_get(
    OV_INSTPTR_iec61131stdfb_AND          pobj
) {
    return &pobj->v_OUT;
}

OV_DLLFNCEXPORT void iec61131stdfb_AND_shutdown(OV_INSTPTR_ov_object pobj) {

	unsigned int i;
	
	OV_INSTPTR_iec61131stdfb_AND pinst = Ov_StaticPtrCast(iec61131stdfb_AND, pobj);
	
	STDFB_FREE_VEC(pinst->v_IN1);
	STDFB_FREE_VEC(pinst->v_IN2);
	STDFB_FREE_VEC(pinst->v_OUT);
	ov_object_shutdown(pobj);
}


OV_DLLFNCEXPORT void iec61131stdfb_AND_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    
	unsigned int i;
	
	OV_INSTPTR_iec61131stdfb_AND pinst = Ov_StaticPtrCast(iec61131stdfb_AND, pfb);
	
	if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == (pinst->v_IN2.value.vartype & OV_VT_KSMASK))
	{
		
		STDFB_FREE_VEC(pinst->v_OUT);		//free memory of preexisting out-vector
		if(!(pinst->v_IN1.value.vartype & OV_VT_ISVECTOR))
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				case OV_VT_BOOL:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = pinst->v_IN1.value.valueunion.val_bool & pinst->v_IN2.value.valueunion.val_bool;
				break;
				
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_UINT;
					pinst->v_OUT.value.valueunion.val_uint = pinst->v_IN1.value.valueunion.val_uint & pinst->v_IN2.value.valueunion.val_uint;
				break;
				
				case OV_VT_BYTE:
					pinst->v_OUT.value.vartype = OV_VT_BYTE;
					pinst->v_OUT.value.valueunion.val_byte = pinst->v_IN1.value.valueunion.val_byte & pinst->v_IN2.value.valueunion.val_byte;
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: logic AND of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
		else
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_BOOL_VEC:
					STDFB_VEC_AND(BOOL, bool);
				break;
				
				case OV_VT_UINT_VEC:
					STDFB_VEC_AND(UINT, uint);
				break;
				
				case OV_VT_BYTE_VEC:
					STDFB_VEC_AND(BYTE, byte);
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: logic AND of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
		
	/************** handling states and timesdtamps ********************************/
		
#include "state_2in.c"
	
	}
	else
	{
		pinst->v_OUT.value.vartype = OV_VT_BOOL;
		pinst->v_OUT.value.valueunion.val_bool = FALSE;
		STDFB_FREE_VEC(pinst->v_OUT);
		ov_logfile_error("%s: trying to use inputs of different types for AND-block", pinst->v_identifier); 
	}
	
    return;
}

