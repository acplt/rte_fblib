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
*    functionblock                       				    *
*                                                       		    *
*    bistable element with reset dominance (VDI/VDE 3696)                   *
*                                                                           *
****************************************************************************/
/*
*   type: rsff
*   ==========
*/
/*
*   history
*   -------
*   created : 21.5.1999
*   author  : Michael Klamann, Chair of Process Control Engineering, RWTH Aachen
*/
/*
*   description
*   -----------
*   Equal to standardfunction RS in IEC 1131-3.
*/
#ifndef OV_COMPILE_LIBRARY_vdivde3696
#define OV_COMPILE_LIBRARY_vdivde3696
#endif
/*
*   C-Includes
*   ----------
*   none
*/
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

OV_DLLFNCEXPORT OV_RESULT vdivde3696_rsff_constructor(
	OV_INSTPTR_ov_object	pobj
) {
	OV_RESULT res;
	OV_INSTPTR_vdivde3696_rsff prsff;

	res = fb_functionblock_constructor(pobj);
	if (Ov_Fail(res)) return res;
	prsff = Ov_StaticPtrCast(vdivde3696_rsff, pobj);
	prsff->v_en = TRUE;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT void vdivde3696_rsff_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
	OV_INSTPTR_vdivde3696_rsff port = Ov_StaticPtrCast(vdivde3696_rsff, pfb);

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
	  /* set enable output to TRUE */
	  port->v_eno = TRUE;

	  if (port->v_r1) /* reset active ? */
	  {
	    /* output to FALSE */
	    port->v_q = FALSE;
	  }
	  else if (port->v_s) /* set active ? */
	       {
		 /* ouput to TRUE */
		 port->v_q = TRUE;
	       }
	    /* else do nothing  -> output retains last cycle value */
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







