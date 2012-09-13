#include"xirscript/sl_state.h"
#include"xirscript/xir_token.h"
enum Xir_Top_Input_Type
{
	XP_OTHER=0,
	XP_NEWLINE,
	XP_COMMA,
	XP_COLON,
	XP_AMPERSAND,
	XP_DOLLAR,
	XP_L_RB,
	XP_R_RB,
	XP_L_SB,
	XP_R_SB,
	XP_COMMENT,
	XP_WS,
	XP_LETTER,
	XP_SIN_QUOTE,
	XP_DOU_QUOTE,
};

static XirState* Xir_Top_Targets[]=
{
	&Err_State,
	&Specific_Symbol_Newline,
	&Specific_Symbol_Comma,
	&Specific_Symbol_Colon,
	&Specific_Symbol_Ampersand,
	&Specific_Symbol_Dollar,
	&Specific_Symbol_L_RB,
	&Specific_Symbol_R_RB,
	&Specific_Symbol_L_SB,
	&Specific_Symbol_R_SB,
	&Comment_Body,
	&WS_Body,
	&Simple_Str_Body,
	&Single_Quote_Str_Body,
	&Double_Quote_Str_Body,
};

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,11,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	11,0,14,10,5,0,4,13,0,0,0,0,2,0,0,0,12,12,12,12,12,12,12,12,12,12,3,0,0,0,0,0,
	0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,8,0,9,0,0,
	0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,6,0,7,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

XirState Xir_Top=
{
	"Xir_Top",
	input_map,
	0,
	XT_UNKOWN,
	Xir_Top_Targets,
};


XirState Err_State=
{
	"Err_State",
	input_map,
	0,
	XT_UNKOWN,
	0,
};















