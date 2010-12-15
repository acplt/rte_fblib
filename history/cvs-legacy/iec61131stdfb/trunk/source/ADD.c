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
*   ADD.c
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
#include "libov/ov_macros.h"
#include "libov/ov_logfile.h"
#include "libov/ov_string.h"

#include <math.h>
#include <float.h>

#define OV_DEBUG

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ADD_IN1_set(
    OV_INSTPTR_iec61131stdfb_ADD          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_IN1, value);
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ADD_IN2_set(
    OV_INSTPTR_iec61131stdfb_ADD          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_IN2, value);
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_ADD_OUT_get(
    OV_INSTPTR_iec61131stdfb_ADD          pobj
) {
    return &pobj->v_OUT;
}

OV_DLLFNCEXPORT void iec61131stdfb_ADD_shutdown(OV_INSTPTR_ov_object pobj) {

	unsigned int i;
	
	OV_INSTPTR_iec61131stdfb_ADD pinst = Ov_StaticPtrCast(iec61131stdfb_ADD, pobj);
	
	STDFB_FREE_VEC(pinst->v_IN1);
	STDFB_FREE_VEC(pinst->v_IN2);
	STDFB_FREE_VEC(pinst->v_OUT);
	ov_object_shutdown(pobj);
}


OV_DLLFNCEXPORT void iec61131stdfb_ADD_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    unsigned int i;
	double dbl_temp;
	
	OV_INSTPTR_iec61131stdfb_ADD pinst = Ov_StaticPtrCast(iec61131stdfb_ADD, pfb);
	
	
		
	if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == (pinst->v_IN2.value.vartype & OV_VT_KSMASK))	//only variables of the same type can be added, save for time and tims_span
	{
		
		STDFB_FREE_VEC(pinst->v_OUT);		//free memory of preexisting out-vector
		if(!(pinst->v_IN1.value.vartype & OV_VT_ISVECTOR))		//handling scalars
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT:
					pinst->v_OUT.value.vartype = OV_VT_INT;
					pinst->v_OUT.value.valueunion.val_int = pinst->v_IN1.value.valueunion.val_int + pinst->v_IN2.value.valueunion.val_int;
				break;
				
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_UINT;
					pinst->v_OUT.value.valueunion.val_uint = pinst->v_IN1.value.valueunion.val_uint + pinst->v_IN2.value.valueunion.val_uint;
				break;
				
				case OV_VT_SINGLE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					dbl_temp = pinst->v_IN1.value.valueunion.val_single + pinst->v_IN2.value.valueunion.val_single;
					STDFB_CONV_DBL_FLT(dbl_temp, pinst->v_OUT.value.valueunion.val_single);
				break;
				
				case OV_VT_DOUBLE:
					pinst->v_OUT.value.vartype = OV_VT_DOUBLE;
					dbl_temp = pinst->v_IN1.value.valueunion.val_double + pinst->v_IN2.value.valueunion.val_double;
					if((dbl_temp == HUGE_VAL) || (dbl_temp == -HUGE_VAL))
					{
						ov_logfile_error("%s: result exceeds range of double", pinst->v_identifier);
						dbl_temp = 0;
					}
					pinst->v_OUT.value.valueunion.val_double = dbl_temp;
				break;

				case OV_VT_BYTE:
					pinst->v_OUT.value.vartype = OV_VT_BYTE;
					pinst->v_OUT.value.valueunion.val_byte = pinst->v_IN1.value.valueunion.val_byte + pinst->v_IN2.value.valueunion.val_byte;
					ov_logfile_warning("%s: addition of bitstring", pinst->v_identifier);
				break;
				
				case OV_VT_BOOL:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = pinst->v_IN1.value.valueunion.val_bool | pinst->v_IN2.value.valueunion.val_bool;
					ov_logfile_warning("%s: addition of boolean, applying logical OR", pinst->v_identifier);
				break;
						
				case OV_VT_TIME_SPAN:
					pinst->v_OUT.value.vartype = OV_VT_TIME_SPAN;
					dbl_temp = (pinst->v_IN1.value.valueunion.val_time_span.usecs + pinst->v_IN2.value.valueunion.val_time_span.usecs);
					dbl_temp += (double)(pinst->v_IN1.value.valueunion.val_time_span.secs + pinst->v_IN2.value.valueunion.val_time_span.secs) * 1000000;
					dbl_temp /= 1000000;
					pinst->v_OUT.value.valueunion.val_time_span.secs = dbl_temp;
					pinst->v_OUT.value.valueunion.val_time_span.usecs = (dbl_temp - pinst->v_OUT.value.valueunion.val_time_span.secs) * 1000000;
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: addition of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
		else		//handling vectors
		{
			
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT_VEC:
					STDFB_VEC_ADD(INT, int);
				break;
				
				case OV_VT_UINT_VEC:
					STDFB_VEC_ADD(UINT, uint);
				break;
				
				case OV_VT_SINGLE_VEC:
					STDFB_VEC_ADD_F(SINGLE, single);
				break;
				
				case OV_VT_DOUBLE_VEC:
					STDFB_VEC_ADD_F(DOUBLE, double);
				break;

				case OV_VT_BYTE_VEC:
					ov_logfile_warning("%s: addition of bitstrings requested", pinst->v_identifier);
					STDFB_VEC_ADD(BYTE, byte);
				break;
				
				case OV_VT_BOOL_VEC:
					pinst->v_OUT.value.vartype = OV_VT_BOOL_VEC;
					ov_logfile_warning("%s: addition of boolean, applying logical OR", pinst->v_identifier);
					if(pinst->v_IN1.value.valueunion.val_bool_vec.veclen == pinst->v_IN2.value.valueunion.val_bool_vec.veclen)
					{
						if(Ov_OK(Ov_SetDynamicVectorLength(&pinst->v_OUT.value.valueunion.val_bool_vec, pinst->v_IN1.value.valueunion.val_bool_vec.veclen, BOOL)))
						{
							for(i=0; i<pinst->v_IN1.value.valueunion.val_bool_vec.veclen; i++)
							{
								pinst->v_OUT.value.valueunion.val_bool_vec.value[i] = pinst->v_IN1.value.valueunion.val_bool_vec.value[i] | 
									pinst->v_IN2.value.valueunion.val_bool_vec.value[i];
							}
						}
						else
						{
							ov_logfile_error("%s: allocation of memory failed, no operation performed", pinst->v_identifier);
							return;
						}
					}
					else
					{
						ov_logfile_error("%s: vectors have different lengths, operation not possible", pinst->v_identifier);
						Ov_SetDynamicVectorLength(&pinst->v_OUT.value.valueunion.val_bool_vec, 0, BOOL);
					}
					
				break;
						
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: addition of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
	}
	else
	{	//timespan can be added to time. this is the only allowed case fpr different types
		if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == OV_VT_TIME && (pinst->v_IN2.value.vartype & OV_VT_KSMASK) == OV_VT_TIME_SPAN)
		{
			pinst->v_OUT.value.vartype = OV_VT_TIME;
			dbl_temp = (pinst->v_IN1.value.valueunion.val_time.usecs + pinst->v_IN2.value.valueunion.val_time_span.usecs);
			dbl_temp += (double)(pinst->v_IN1.value.valueunion.val_time.secs + pinst->v_IN2.value.valueunion.val_time_span.secs) * 1000000;
			dbl_temp /= 1000000;
			pinst->v_OUT.value.valueunion.val_time.secs = dbl_temp;
			pinst->v_OUT.value.valueunion.val_time.usecs = (dbl_temp - pinst->v_OUT.value.valueunion.val_time_span.secs) * 1000000;
			if(dbl_temp < 0)
				ov_logfile_error("%s: result time negativ", pinst->v_identifier);
		}
		else
		{
			ov_logfile_error("%s: trying to use inputs of different types for ADD-block", pinst->v_identifier); 
			STDFB_FREE_VEC(pinst->v_OUT);
			pinst->v_OUT.value.vartype = OV_VT_BOOL;
			pinst->v_OUT.value.valueunion.val_bool = FALSE;
			return;
		}
	}

/************** handling states and timesdtamps ********************************/
		
#include "state_2in.c"
    
	return;
}

