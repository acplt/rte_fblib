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
*   MUL.c
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
#include "libov/ov_string.h"
#include "helper.h"
#include <limits.h>

#include <math.h>

OV_RESULT
iec61131stdfb_MUL_setType
(OV_INSTPTR_iec61131stdfb_MUL pobj, OV_VAR_TYPE type)
{
  if (iec61131stdfb_isConnected (Ov_PtrUpCast (fb_functionblock, pobj)))
    return OV_ERR_NOACCESS;
  else
  {
    
    switch(type & OV_VT_KSMASK)
	{
		case OV_VT_INT:
		case OV_VT_UINT:
		case OV_VT_SINGLE:
		case OV_VT_DOUBLE:
		case OV_VT_BYTE:
		case OV_VT_INT_VEC:
		case OV_VT_UINT_VEC:
		case OV_VT_SINGLE_VEC:
		case OV_VT_DOUBLE_VEC:
		case OV_VT_BYTE_VEC:
			pobj->v_IN1.value.vartype = type;
			pobj->v_IN2.value.vartype = type;
			pobj->v_OUT.value.vartype = type;
			return OV_ERR_OK;
		default:
			return OV_ERR_BADPARAM;
	}
		return OV_ERR_GENERIC;
  }
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_MUL_IN1_set(
    OV_INSTPTR_iec61131stdfb_MUL          pobj,
    const OV_ANY*  value
) {
    OV_RESULT res;
  
	if ((value->value.vartype & OV_VT_KSMASK) == (pobj->v_IN1.value.vartype & OV_VT_KSMASK))
		return ov_variable_setanyvalue (&pobj->v_IN1, value);
	else if((value->value.vartype & OV_VT_KSMASK) != OV_VT_TIME_SPAN)
	{
		iec61131stdfb_freeVec(&pobj->v_IN1);
		iec61131stdfb_freeVec(&pobj->v_IN2);
		iec61131stdfb_freeVec(&pobj->v_OUT);		//free memory of preexisting out-vector
		res = iec61131stdfb_MUL_setType (pobj, value->value.vartype); 
		if (Ov_OK (res))
			return ov_variable_setanyvalue (&pobj->v_IN1, value);
		else return res;
	}
	else if(!iec61131stdfb_isConnected(Ov_PtrUpCast(fb_functionblock, pobj)))
	{
		iec61131stdfb_freeVec(&pobj->v_IN1);
		iec61131stdfb_freeVec(&pobj->v_IN2);
		iec61131stdfb_freeVec(&pobj->v_OUT);
		res = ov_variable_setanyvalue(&pobj->v_IN1, value);
		if(Ov_OK(res))
		{
			pobj->v_IN2.value.vartype = OV_VT_SINGLE;
			pobj->v_OUT.value.vartype = OV_VT_TIME_SPAN;
			return OV_ERR_OK;
		}
		else
			return res;
	}
	else
		return OV_ERR_NOACCESS;
		
	
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_MUL_IN2_set(
    OV_INSTPTR_iec61131stdfb_MUL          pobj,
    const OV_ANY*  value
) {
    OV_RESULT res;
  
	if ((value->value.vartype & OV_VT_KSMASK) == (pobj->v_IN2.value.vartype & OV_VT_KSMASK))
		return ov_variable_setanyvalue (&pobj->v_IN2, value);
	else if((pobj->v_IN1.value.vartype & OV_VT_KSMASK) != OV_VT_TIME_SPAN)
	{
		iec61131stdfb_freeVec(&pobj->v_IN1);
		iec61131stdfb_freeVec(&pobj->v_IN2);
		iec61131stdfb_freeVec(&pobj->v_OUT);		//free memory of preexisting out-vector
		res = iec61131stdfb_MUL_setType (pobj, value->value.vartype); 
		if (Ov_OK (res))
			return ov_variable_setanyvalue (&pobj->v_IN1, value);
		else return res;
	}
	else if(!iec61131stdfb_isConnected(Ov_PtrUpCast(fb_functionblock, pobj)))
	{
		iec61131stdfb_freeVec(&pobj->v_IN2);
			
		switch(value->value.vartype & OV_VT_KSMASK)
		{
			case OV_VT_SINGLE:
			case OV_VT_DOUBLE:
			case OV_VT_INT:
			case OV_VT_UINT:
				return ov_variable_setanyvalue (&pobj->v_IN2, value);
			default:
				return OV_ERR_BADPARAM;
				
		}
	}
	else
		return OV_ERR_NOACCESS;
		
	
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_MUL_OUT_get(
    OV_INSTPTR_iec61131stdfb_MUL          pobj
) {
    return &pobj->v_OUT;
}


OV_DLLFNCEXPORT void iec61131stdfb_MUL_shutdown(OV_INSTPTR_ov_object pobj) {

	OV_INSTPTR_iec61131stdfb_MUL pinst = Ov_StaticPtrCast(iec61131stdfb_MUL, pobj);
	
	iec61131stdfb_freeVec(&pinst->v_IN1);
	iec61131stdfb_freeVec(&pinst->v_IN2);
	iec61131stdfb_freeVec(&pinst->v_OUT);
	ov_object_shutdown(pobj);
}


OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_MUL_constructor(OV_INSTPTR_ov_object pobj) {

	OV_RESULT res;
	OV_INSTPTR_iec61131stdfb_MUL pinst = Ov_StaticPtrCast(iec61131stdfb_MUL, pobj);
	
	res = ov_object_constructor(pobj);
	
	if(Ov_OK(res))
	{
		pinst->v_IN1.value.valueunion.val_double = 0;
		pinst->v_IN2.value.valueunion.val_double = 0;
		pinst->v_OUT.value.valueunion.val_double = 0;
		pinst->v_IN1.value.vartype = OV_VT_SINGLE;
		pinst->v_IN2.value.vartype = OV_VT_SINGLE;
		pinst->v_OUT.value.vartype = OV_VT_SINGLE;
		return OV_ERR_OK;
	}
	else
		return res;
}

OV_DLLFNCEXPORT void iec61131stdfb_MUL_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	unsigned int i;
	double d_temp;
	
#define STDFB_STATE_CHECK
	OV_BOOL STDFB_bad_operation = FALSE;
	
    OV_INSTPTR_iec61131stdfb_MUL pinst = Ov_StaticPtrCast(iec61131stdfb_MUL, pfb);
	
	if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == (pinst->v_IN2.value.vartype & OV_VT_KSMASK))
	{
		
		iec61131stdfb_freeVec(&pinst->v_OUT);		//free memory of preexisting out-vector
		if(!(pinst->v_IN1.value.vartype & OV_VT_ISVECTOR))
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT:
					pinst->v_OUT.value.vartype = OV_VT_INT;
					pinst->v_OUT.value.valueunion.val_int = pinst->v_IN1.value.valueunion.val_int * pinst->v_IN2.value.valueunion.val_int;
				break;
				
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_UINT;
					pinst->v_OUT.value.valueunion.val_uint = pinst->v_IN1.value.valueunion.val_uint * pinst->v_IN2.value.valueunion.val_uint;
				break;
				
				case OV_VT_SINGLE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					pinst->v_OUT.value.valueunion.val_single = pinst->v_IN1.value.valueunion.val_single * pinst->v_IN2.value.valueunion.val_single;
					if((pinst->v_OUT.value.valueunion.val_single == HUGE_VAL) || (pinst->v_OUT.value.valueunion.val_single == -HUGE_VAL))
					{
						ov_logfile_error("%s: result exceeds range of single", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
				break;
				
				case OV_VT_DOUBLE:
					pinst->v_OUT.value.vartype = OV_VT_DOUBLE;
					pinst->v_OUT.value.valueunion.val_double = pinst->v_IN1.value.valueunion.val_double * pinst->v_IN2.value.valueunion.val_double;
					if((pinst->v_OUT.value.valueunion.val_double == HUGE_VAL) || (pinst->v_OUT.value.valueunion.val_double == -HUGE_VAL))
					{
						ov_logfile_error("%s: result exceeds range of double", pinst->v_identifier);
						STDFB_bad_operation = TRUE;
					}
				break;

				case OV_VT_BYTE:
					pinst->v_OUT.value.vartype = OV_VT_BYTE;
					pinst->v_OUT.value.valueunion.val_byte = pinst->v_IN1.value.valueunion.val_byte * pinst->v_IN2.value.valueunion.val_byte;
					ov_logfile_warning("%s: multiplication of bitstring", pinst->v_identifier);
				break;
					
					
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: multiplication of given datatypes senseless", pinst->v_identifier);
					STDFB_bad_operation = TRUE;
				break;
			}
		}
		else
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT_VEC:
					STDFB_VEC_MUL(INT, int);
				break;
				
				case OV_VT_UINT_VEC:
					STDFB_VEC_MUL(UINT, uint);
				break;
				
				case OV_VT_SINGLE_VEC:
					STDFB_VEC_MUL_F(SINGLE, single);
				break;
				
				case OV_VT_DOUBLE_VEC:
					STDFB_VEC_MUL_F(DOUBLE, double);
				break;

				case OV_VT_BYTE_VEC:
					ov_logfile_warning("%s: addition of bitstrings requested", pinst->v_identifier);
					STDFB_VEC_MUL(BYTE, byte);
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: multiplication of given datatypes senseless", pinst->v_identifier);
					STDFB_bad_operation = TRUE;
				break;
			}
		}
		
	
	
	}
	else
	{
		if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == OV_VT_TIME_SPAN)
		{
			switch(pinst->v_IN2.value.vartype & OV_VT_KSMASK)
			{
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_TIME_SPAN;
					d_temp = ((double)pinst->v_IN1.value.valueunion.val_time_span.usecs * pinst->v_IN2.value.valueunion.val_uint);
					d_temp += (double)((double)pinst->v_IN1.value.valueunion.val_time_span.secs * pinst->v_IN2.value.valueunion.val_uint) * 1000000;
					d_temp /= 1000000;
					pinst->v_OUT.value.valueunion.val_time_span.secs = (OV_INT) d_temp;
					pinst->v_OUT.value.valueunion.val_time_span.usecs = (OV_INT) ((d_temp - pinst->v_OUT.value.valueunion.val_time_span.secs) * 1000000);
				break;
				
				case OV_VT_INT:
					pinst->v_OUT.value.vartype = OV_VT_TIME_SPAN;
					d_temp = ((double)pinst->v_IN1.value.valueunion.val_time_span.usecs * pinst->v_IN2.value.valueunion.val_int);
					d_temp += (double)(pinst->v_IN1.value.valueunion.val_time_span.secs * pinst->v_IN2.value.valueunion.val_int) * 1000000;
					d_temp /= 1000000;
					pinst->v_OUT.value.valueunion.val_time_span.secs = (OV_INT) d_temp;
					pinst->v_OUT.value.valueunion.val_time_span.usecs = (OV_INT) ((d_temp - pinst->v_OUT.value.valueunion.val_time_span.secs) * 1000000);
				break;
				
				case OV_VT_SINGLE:
					pinst->v_OUT.value.vartype = OV_VT_TIME_SPAN;
					d_temp = ((double)pinst->v_IN1.value.valueunion.val_time_span.usecs * pinst->v_IN2.value.valueunion.val_single);
					d_temp += (double)(pinst->v_IN1.value.valueunion.val_time_span.secs * pinst->v_IN2.value.valueunion.val_single) * 1000000;
					d_temp /= 1000000;
					pinst->v_OUT.value.valueunion.val_time_span.secs = (OV_INT) d_temp;
					pinst->v_OUT.value.valueunion.val_time_span.usecs = (OV_INT) ((d_temp - pinst->v_OUT.value.valueunion.val_time_span.secs) * 1000000);
				break;
				
				case OV_VT_DOUBLE:
					pinst->v_OUT.value.vartype = OV_VT_TIME_SPAN;
					d_temp = ((double)pinst->v_IN1.value.valueunion.val_time_span.usecs * pinst->v_IN2.value.valueunion.val_double);
					d_temp += (double)(pinst->v_IN1.value.valueunion.val_time_span.secs * pinst->v_IN2.value.valueunion.val_double) * 1000000;
					d_temp /= 1000000;
					pinst->v_OUT.value.valueunion.val_time_span.secs = (OV_INT) d_temp;
					pinst->v_OUT.value.valueunion.val_time_span.usecs = (OV_INT) ((d_temp - pinst->v_OUT.value.valueunion.val_time_span.secs) * 1000000);
				break;
				
				default:
					iec61131stdfb_freeVec(&pinst->v_OUT);
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_error("%s: trying to use inputs of different types for MUL-block", pinst->v_identifier);
					STDFB_bad_operation = TRUE;
					return;
				
			}
		}
		else		//this should never happen due to type control in set accessors, but just to make sure....
		{
			pinst->v_OUT.value.vartype = OV_VT_BOOL;
			pinst->v_OUT.value.valueunion.val_bool = FALSE;
			iec61131stdfb_freeVec(&pinst->v_OUT);
			ov_logfile_error("%s: trying to use inputs of different types for MUL-block", pinst->v_identifier);
			STDFB_bad_operation = TRUE;
			return;
		}
	}
	
			/************** handling states and timestamps ********************************/
		
#include "state_2in.c"
	
	return;
}

