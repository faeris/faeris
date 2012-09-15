#ifndef _FEARY_XIR_TOKEN_H_
#define _FEARY_XIR_TOKEN_H_
#include<string>
enum XirToken
{
	XT_UNKOWN=0,
	XT_ERROR,
	XT_SIM_STR,
	XT_DOU_STR,
	XT_SIN_STR,

	XT_NEWLINE,
	XT_COMMA,

	XT_COLON,
	XT_AMPERSAND,
	XT_DOLLAR,
	XT_L_RB,
	XT_R_RB,
	XT_L_SB,
	XT_R_SB,

	XT_WS,
	XT_COMMENT,
	XT_EOF,

	XT_TOKEN_NU,
};

std::string XirToken_Name(int token);
#endif  /*_FEARY_XIR_TOKEN_H_*/



