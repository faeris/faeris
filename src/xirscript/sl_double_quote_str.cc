#include"sl_state.h"
#include"xir_token.h"

extern XirState Double_Quote_Str_Begin;
extern XirState Double_Quote_Str_Body;
extern XirState Double_Quote_Str_Esc;
extern XirState Double_Quote_Str_End;

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
enum  Double_Str_Input_Type
{
	DS_ERR=0,
	DS_SLASH=1,
	DS_QUOTE=2,
};

static XirState* Double_Quote_Str_Begin_Targets[]=
{&Err_State,&Err_State,&Double_Quote_Str_Body};

XirState Double_Quote_Str_Begin=
{
	"Double_Quote_Str_Begin",
	input_map,
	0,
	XT_UNKOWN,
	Double_Quote_Str_Begin_Targets,
};

static XirState* Double_Quote_Str_Body_Targets[]=
{&Double_Quote_Str_Body,&Double_Quote_Str_Esc,&Double_Quote_Str_End};

XirState Double_Quote_Str_Body=
{
	"Double_Quote_Str_Body",
	input_map,
	0,
	XT_UNKOWN,
	Double_Quote_Str_Body_Targets,
};

static XirState* Double_Quote_Str_Esc_Targets[]=
{&Double_Quote_Str_Body,&Double_Quote_Str_Body,&Double_Quote_Str_Body};

XirState Double_Quote_Str_Esc=
{
	"Dobule_Quote_Str_Esc",
	input_map,
	0,
	XT_UNKOWN,
	Double_Quote_Str_Esc_Targets,
};

static XirState* Double_Quote_Str_End_Targets[]=
{ &Err_State,&Err_State,&Err_State};

XirState Double_Quote_Str_End=
{
	"Double_Quote_Str_End",
	input_map,
	1,
	XT_DOU_STR,
	Double_Quote_Str_End_Targets,
};
