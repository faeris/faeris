#include"xir_token.h"
#include"sl_state.h"
#include"xir_state.h"

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static XirState* Comment_Begin_Targets[]=
{ &Err_State,&Comment_Body,&Err_State};

XirState Comment_Begin=
{
	"Comment_Begin",
	input_map,
	0,
	XT_UNKOWN,
	Comment_Begin_Targets,
};

static XirState* Comment_Body_Targets[]=
{ &Comment_Body,&Comment_Body,&Comment_End};

XirState Comment_Body=
{
	"Comment_Body",
	input_map,
	0,
	XT_UNKOWN,
	Comment_Body_Targets,
};

static XirState* Comment_End_Targets[]=
{ &Err_State,&Err_State,&Err_State};

XirState Comment_End=
{
	"Comment_End",
	input_map,
	1,
	XT_COMMENT,
	Comment_End_Targets,
};

