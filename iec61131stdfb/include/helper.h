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
*   helper.h
*
*   History
*   -------
*   2011-04-04   File created
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
#include "fb.h"
#include "ov_ov.h"
#include "ov_macros.h"


OV_BOOL 
iec61131stdfb_isConnected 
(OV_INSTPTR_fb_functionblock fb);

OV_RESULT iec61131stdfb_freeVec(OV_ANY* pobj);