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
*   FIND.c
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
#include "ov_macros.h"
#include "ov_logfile.h"
#include "ov_string.h"



OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_FIND_IN1_set(
    OV_INSTPTR_iec61131stdfb_FIND          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_IN1,value);
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_FIND_IN2_set(
    OV_INSTPTR_iec61131stdfb_FIND          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_IN2,value);
}

OV_DLLFNCEXPORT OV_UINT iec61131stdfb_FIND_OUT_get(
    OV_INSTPTR_iec61131stdfb_FIND          pobj
) {
    return pobj->v_OUT;
}


OV_DLLFNCEXPORT void iec61131stdfb_FIND_destructor(OV_INSTPTR_ov_object pobj) {

	OV_INSTPTR_iec61131stdfb_FIND pinst = Ov_StaticPtrCast(iec61131stdfb_FIND, pobj);
	
	ov_string_setvalue(&pinst->v_IN1, "");
	ov_string_setvalue(&pinst->v_IN2, "");
	
	fb_functionblock_destructor(pobj);
}


OV_DLLFNCEXPORT void iec61131stdfb_FIND_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	unsigned int i;
	unsigned int cont_loop;
	
	unsigned int length;
	unsigned int search_length;
	
	OV_BOOL found;
	
	OV_INSTPTR_iec61131stdfb_FIND pinst = Ov_StaticPtrCast(iec61131stdfb_FIND, pfb);
	
	length = ov_string_getlength(pinst->v_IN1);
	search_length = ov_string_getlength(pinst->v_IN2);
	
	found = 0;
	
	if(length >= search_length)
	{
		if(search_length && length)
		{
			for(cont_loop = 0; cont_loop <= (length - search_length) && !found ; cont_loop++)
			{
				if(pinst->v_IN1[cont_loop] == pinst->v_IN2[0])		//find first character
				{
					for(i=0; i < search_length; i++)
					{
						if(pinst->v_IN1[cont_loop + i] == pinst->v_IN2[i])
						{
							found = 1;
						}
						else
						{
							found = 0;
							break;
						}
					}
				}
			}
			
			if(found)
			{
				pinst->v_OUT = cont_loop;
			}
			else
				pinst->v_OUT = 0;

		}
		else
		{
			ov_logfile_error("%s: at least one input not specified", pinst->v_identifier);
			pinst->v_OUT = 0;
		}
	}
	else
	{
		ov_logfile_warning("%s: string in IN2 is longer than string in IN1, ich cannot be found", pinst->v_identifier);
		pinst->v_OUT = 0;
	}

    return;
}

