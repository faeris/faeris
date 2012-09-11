#include"xir_token.h"
#include"sl_state.h"
#include"xir_state.h"
enum Sim_Str_Input_Type
{
	SS_ERR=0,
	SS_NORMAL,
	SS_WS,	
};

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};


static XirState* Simple_Str_Begin_Targets[]={&Err_State,&Simple_Str_Body,&Err_State};

XirState Simple_Str_Begin=
{
	"Simple_Str_Begin",
	input_map,
	0,
	XT_UNKOWN,
	Simple_Str_Begin_Targets,
};

static XirState* Simple_Str_Body_Targets[]= {&Err_State,&Simple_Str_Body,&Simple_Str_Space};

XirState Simple_Str_Body=
{
	"Simple_Str_Body",
	input_map,
	1,
	XT_SIM_STR,
	Simple_Str_Body_Targets,
};

static XirState* Simple_Str_Space_Targets[]={&Err_State,&Simple_Str_Body,&Simple_Str_Space};
XirState Simple_Str_Space=
{
	"Simple_Str_Space",
	input_map,
	0,
	XT_UNKOWN,
	Simple_Str_Space_Targets,
};

