#include"xir_token.h"
#include"sl_state.h"
#include"xir_state.h"

static unsigned char begin_input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,5,0,4,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,9,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,7,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
enum  Specific_Input_type
{
	SI_OTHER=0,
	SI_NEWLINE,
	SI_COMMA,
	SI_COLON,
	SI_AMPERSAND,
	SI_DOLLAR,
	SI_L_RB,
	SI_R_RB,
	SI_L_SB,
	SI_R_SB,
};

static XirState* Specific_Symbol_Begin_Targets[]=
{
	&Err_State,
	&Specific_Symbol_Newline,
	&Specific_Symbol_Comma,
	&Specific_Symbol_Colon,
	&Specific_Symbol_AMPERSAND,
	&Specific_Symbol_Dollar,
	&Specific_Symbol_L_RB,
	&Specific_Symbol_R_RB,
	&Specific_Symbol_L_SB,
	&Specific_Symbol_R_SB,
};

XirState Specific_Symbol_Begin=
{
	"Specific_Symbol_Begin",
	begin_input_map,
	0,
	XT_UNKOWN,
	Specific_Symbol_Begin_Targets,
};






















