
/******************************************************************************
*
*   FILE
*   ----
*   FBComCommon.c
*
*   History
*   -------
*   2013-05-18   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_fbcomlib
#define OV_COMPILE_LIBRARY_fbcomlib
#endif


#include "fbcomlib.h"
#include "ov_macros.h"
#include "config.h"


OV_DLLFNCEXPORT OV_STRING fbcomlib_FBComCommon_host_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_host;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_host_set(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj,
    const OV_STRING  value
) {
	if(!(pobj->v_doSend)){
		return ov_string_setvalue(&pobj->v_host,value);
	}
	else {
		return OV_ERR_NOACCESS;
	}
}

OV_DLLFNCEXPORT OV_STRING fbcomlib_FBComCommon_server_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_server;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_server_set(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj,
    const OV_STRING  value
) {
	if(!(pobj->v_doSend)){
		return ov_string_setvalue(&pobj->v_server,value);
	}
	else {
		return OV_ERR_NOACCESS;
	}
}

OV_DLLFNCEXPORT OV_STRING fbcomlib_FBComCommon_path_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_path;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_path_set(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj,
    const OV_STRING  value
) {
	if(!(pobj->v_doSend)){
		return ov_string_setvalue(&pobj->v_path,value);
	}
	else {
		return OV_ERR_NOACCESS;
	}
}

OV_DLLFNCEXPORT OV_BOOL fbcomlib_FBComCommon_doSend_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_doSend;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_doSend_set(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj,
    const OV_BOOL  value
) {
    if(value && (!pobj->v_doSend))
    		pobj->v_sendRequested = TRUE;
	pobj->v_doSend = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT void fbcomlib_FBComCommon_resetAbstract(OV_INSTPTR_fbcomlib_FBComCommon this)
{
	fbcomlib_FBComCommon_doCyclic_set(this, FALSE);
	fbcomlib_FBComCommon_doSend_set(this, FALSE);
	fbcomlib_FBComCommon_state_set(this, FBCOMLIB_STATE_INIT);
	this->v_sendRequested = FALSE;
	this->v_opResult = OV_ERR_OK;
	this->v_errorCode = OV_ERR_OK;
	return;
}

OV_DLLFNCEXPORT OV_BOOL fbcomlib_FBComCommon_doCyclic_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_doCyclic;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_doCyclic_set(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj,
    const OV_BOOL  value
) {
	if(value && (!pobj->v_doCyclic))
		pobj->v_sendRequested = TRUE;
	pobj->v_doCyclic = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_STRING fbcomlib_FBComCommon_stateString_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_stateString;
}

OV_DLLFNCEXPORT OV_INT fbcomlib_FBComCommon_state_get(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj
) {
    return pobj->v_state;
}

#define STATE_SET_CASE(state)	\
case	FBCOMLIB_STATE_##state:	\
	pobj->v_state = FBCOMLIB_STATE_##state;	\
    ov_string_setvalue(&(pobj->v_stateString), FBCOMLIB_STATESTR_##state);	\
    return OV_ERR_OK

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_state_set(
    OV_INSTPTR_fbcomlib_FBComCommon          pobj,
    const OV_INT  value
) {

    switch(value)
    {
    STATE_SET_CASE(INIT);
    STATE_SET_CASE(WAITING);
    STATE_SET_CASE(OK);
    STATE_SET_CASE(WRONGINPUT);
    STATE_SET_CASE(INTERNAL_ERROR);
    STATE_SET_CASE(KSAPI_ERROR);
    STATE_SET_CASE(EXTERNAL_ERROR);
    STATE_SET_CASE(TIMEOUT);
    STATE_SET_CASE(UNKNOWN_ERROR);
    default:
    	pobj->v_state = FBCOMLIB_STATE_UNKNOWN_ERROR;
    	ov_string_setvalue(&(pobj->v_stateString), FBCOMLIB_STATESTR_UNKNOWN_ERROR);
    	break;
    }
    return OV_ERR_BADVALUE;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_FBComCommon_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_RESULT    result;

    /* do what the base class does first */
    result = fb_functionblock_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */


    return OV_ERR_OK;
}

