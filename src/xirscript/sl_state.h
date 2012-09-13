#ifndef _FEARY_XIR_SL_STATE_H_
#define _FEARY_XIR_SL_STATE_H_

#include"xirscript/xir_state.h"

extern XirState Err_State;
extern XirState Xir_Top;
/* Dobule Quote String */
extern XirState Double_Quote_Str_Begin;
extern XirState Double_Quote_Str_Body;
extern XirState Double_Quote_Str_Esc;
extern XirState Double_Quote_Str_End;


/* Single Quote String */
extern XirState Single_Quote_Str_Begin;
extern XirState Single_Quote_Str_Body;
extern XirState Single_Quote_Str_End;

/* Simple String */
extern XirState Simple_Str_Begin;
extern XirState Simple_Str_Body;
extern XirState Simple_Str_Space;

/* White space */
extern XirState WS_Begin;
extern XirState WS_Body;

/* Comment */
extern XirState Comment_Begin;
extern XirState Comment_Body;
extern XirState Comment_End;

/* Specific Symbol */
extern XirState Specific_Symbol_Begin;
extern XirState Specific_Symbol_Newline; 
extern XirState Specific_Symbol_Comma; 
extern XirState Specific_Symbol_Colon;
extern XirState Specific_Symbol_Ampersand;
extern XirState Specific_Symbol_Dollar;
extern XirState Specific_Symbol_L_RB;
extern XirState Specific_Symbol_R_RB;
extern XirState Specific_Symbol_L_SB;
extern XirState Specific_Symbol_R_SB;

#endif 

