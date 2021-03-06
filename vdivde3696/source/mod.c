/*
*   Copyright (C) 1998
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
/****************************************************************************
*									    *
*    functionblock                      				    *
*                                                       		    *
*    modulo (VDI/VDE 3696)                                                  *
*                                                                           *
****************************************************************************/
/*
*   type: mod
*   =========
*/
/*
*   history
*   -------
*   created : 12.5.1999
*   author  : Michael Klamann, Chair of Process Control Engineering, RWTH Aachen
*/
/*
*   description
*   -----------
*   Nearly equal to standardfunction MOD in IEC 1131-3.
*   Works with floating point values. The output value will
*   allways be in [0,U2].
*/
#ifndef OV_COMPILE_LIBRARY_vdivde3696
#define OV_COMPILE_LIBRARY_vdivde3696
#endif
/*
*   C-Includes
*   ----------
*/
#include <math.h>
/*  
*   defines
*   -------
*   none
*/
/*
*   modul-declaration
*   -----------------
*/
#include "vdivde3696.h"
#include "ov_macros.h"

OV_DLLFNCEXPORT OV_RESULT vdivde3696_mod_constructor(
	OV_INSTPTR_ov_object	pobj
) {
	OV_RESULT res;
	OV_INSTPTR_vdivde3696_mod pmod;

	res = fb_functionblock_constructor(pobj);
	if (Ov_Fail(res)) return res;
	pmod = Ov_StaticPtrCast(vdivde3696_mod, pobj);
	pmod->v_en = TRUE;
	pmod->v_u2 = 1;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT void vdivde3696_mod_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
	OV_INSTPTR_vdivde3696_mod port = Ov_StaticPtrCast(vdivde3696_mod, pfb);

	/*
	*   local variables
	*   ---------------
	*   none
	*/
	/*
	*   instructions
	*   ------------
	*/

        if (port->v_en) /* functionblock enable */
        {
	  /* check for division by zero */
	  if (port->v_u2 == 0)
	  {
	    /* set enable output to false and modulo output v to zero */
	    port->v_eno = FALSE;
	    port->v_v = 0;
	  }
	  else /* set enable output to true and compute modulo u1/u2 */
	  {
	    port->v_eno = TRUE;
	    port->v_v = port->v_u1 - port->v_u2 * floor (port->v_u1/port->v_u2);
	  }
	}
        else /* functionblock NOT enable */
        {
	  port->v_eno = FALSE;
	}

        /* add 1 to counter */
	port->v_counter = (port->v_counter+1)%10000;

/*******  end  *******/
	return;
	}







