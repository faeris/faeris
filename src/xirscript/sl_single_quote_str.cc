#include"sl_state.h"
#include"xir_token.h"

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};


static XirState* Single_Quote_Str_Begin_Targets[]=
{&Err_State,&Single_Quote_Str_Body};

XirState Single_Quote_Str_Begin=
{
	"Single_Quote_Str_Begin",
	input_map,
	0,
	XT_UNKOWN,
	Single_Quote_Str_Begin_Targets,
};


static XirState* Single_Quote_Str_Body_Targets[]=
{ &Single_Quote_Str_Body,&Single_Quote_Str_End};

XirState Single_Quote_Str_Body=
{
	"Single_Quote_Str_Body",
	input_map,
	0,
	XT_UNKOWN,
	Single_Quote_Str_Body_Targets,
};

static XirState* Single_Quote_Str_End_Targets[]=
{&Err_State,&Err_State};

XirState Single_Quote_Str_End=
{
	"Single_Quote_Str_End",
	input_map,
	1,
	XT_SIN_STR,
	Single_Quote_Str_End_Targets,
};

