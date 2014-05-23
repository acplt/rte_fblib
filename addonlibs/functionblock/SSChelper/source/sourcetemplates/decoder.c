
/******************************************************************************
*
*   FILE
*   ----
*   decoder.c
*
*   History
*   -------
*   2014-03-31   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_SSChelper
#define OV_COMPILE_LIBRARY_SSChelper
#endif


#include "SSChelper.h"
#include "libov/ov_macros.h"


OV_DLLFNCEXPORT OV_RESULT SSChelper_decoder_CMD_set(
    OV_INSTPTR_SSChelper_decoder          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_CMD,value);
}

OV_DLLFNCEXPORT void SSChelper_decoder_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_SSChelper_decoder pinst = Ov_StaticPtrCast(SSChelper_decoder, pfb);

    return;
}

