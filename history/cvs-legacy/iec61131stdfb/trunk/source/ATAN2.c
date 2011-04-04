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
*   ATAN2.c
*
*   History
*   -------
*   2010-11-23   File created
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

#include <math.h>


OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ATAN2_IN1_set(
    OV_INSTPTR_iec61131stdfb_ATAN2          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_IN1, value);
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ATAN2_IN2_set(
    OV_INSTPTR_iec61131stdfb_ATAN2          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_IN2, value);
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_ATAN2_OUT_get(
    OV_INSTPTR_iec61131stdfb_ATAN2          pobj
) {
    return &pobj->v_OUT;
}


OV_DLLFNCEXPORT void iec61131stdfb_ATAN2_shutdown(OV_INSTPTR_ov_object pobj) {

	unsigned int i;
	
	OV_INSTPTR_iec61131stdfb_ATAN2 pinst = Ov_StaticPtrCast(iec61131stdfb_ATAN2, pobj);
	
	STDFB_FREE_VEC(pinst->v_IN1);
	STDFB_FREE_VEC(pinst->v_IN2);
	STDFB_FREE_VEC(pinst->v_OUT);
	ov_object_shutdown(pobj);
}


OV_DLLFNCEXPORT void iec61131stdfb_ATAN2_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	const double Pi = 3.14159265358979323846;
	unsigned int i;
	
    OV_INSTPTR_iec61131stdfb_ATAN2 pinst = Ov_StaticPtrCast(iec61131stdfb_ATAN2, pfb);
	if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == (pinst->v_IN2.value.vartype & OV_VT_KSMASK))
	{
		
		STDFB_FREE_VEC(pinst->v_OUT);		//free memory of preexisting out-vector
		if(!(pinst->v_IN1.value.vartype & OV_VT_ISVECTOR))
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT:
					ov_logfile_warning("%s: atan2 of integers, setting out to single to prevent data loss", pinst->v_identifier);
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					if((pinst->v_IN1.value.valueunion.val_int))
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_int / pinst->v_IN1.value.valueunion.val_int);
					else
						if(pinst->v_IN2.value.valueunion.val_int < 0)
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
						else
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
				break;
				
				case OV_VT_UINT:
					ov_logfile_warning("%s: atan2 of unsigned integers, setting out to single to prevent data loss", pinst->v_identifier);
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					if((pinst->v_IN1.value.valueunion.val_uint))
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_uint / pinst->v_IN1.value.valueunion.val_uint);
					else
						if(pinst->v_IN2.value.valueunion.val_uint < 0)
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
						else
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
				break;
				
				case OV_VT_SINGLE:
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					if((pinst->v_IN1.value.valueunion.val_single))
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_single / pinst->v_IN1.value.valueunion.val_single);
					else
						if(pinst->v_IN2.value.valueunion.val_single < 0)
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
						else
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
				break;
				
				case OV_VT_DOUBLE:
					pinst->v_OUT.value.vartype = OV_VT_DOUBLE;
					if((pinst->v_IN1.value.valueunion.val_double))
						pinst->v_OUT.value.valueunion.val_double = atan(pinst->v_IN2.value.valueunion.val_double / pinst->v_IN1.value.valueunion.val_double);
					else
						if(pinst->v_IN2.value.valueunion.val_double < 0)
							pinst->v_OUT.value.valueunion.val_double = -0.5 * Pi;
						else
							pinst->v_OUT.value.valueunion.val_double = 0.5 * Pi;
				break;

				case OV_VT_BYTE:
					ov_logfile_warning("%s: atan2 of bitstrings, setting out to single to prevent data loss", pinst->v_identifier);
					pinst->v_OUT.value.vartype = OV_VT_SINGLE;
					if((pinst->v_IN1.value.valueunion.val_byte))
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_byte / pinst->v_IN1.value.valueunion.val_byte);
					else
						if(pinst->v_IN2.value.valueunion.val_byte < 0)
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
						else
							pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
					
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: atan2 of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
		else
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_INT_VEC:
					ov_logfile_warning("%s: arctan2 of integers requested, setting out to single to prevent data loss", pinst->v_identifier);
					STDFB_VEC_ATAN2(INT, int);
				break;
				
				case OV_VT_UINT_VEC:
					ov_logfile_warning("%s: arctan2 of unsigned integers requested, setting out to single to prevent data loss", pinst->v_identifier);
					STDFB_VEC_ATAN2(UINT, uint);
				break;
				
				case OV_VT_SINGLE_VEC:
					STDFB_VEC_ATAN2(SINGLE, single);
				break;
				
				case OV_VT_DOUBLE_VEC:
					STDFB_VEC_ATAN2_D(DOUBLE, double);
				break;

				case OV_VT_BYTE_VEC:
					ov_logfile_warning("%s: arctan2 of bitstrings requested, setting out to single to prevent data loss", pinst->v_identifier);
					STDFB_VEC_ATAN2(BYTE, byte);
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: arctan2 of given datatypes senseless", pinst->v_identifier);
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
		ov_logfile_error("%s: trying to use inputs of different types for ATAN2-block", pinst->v_identifier); 
	}
	
    return;
}
