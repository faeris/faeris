#include"xirscript/xir_token.h"
#include"util/marocs.h"
static const char* s_xir_token_name[]=
{
	"XT_UNKOWN",
	"XT_ERROR",
	"XT_SIM_STR",
	"XT_DOU_STR",
	"XT_SIN_STR",
	"XT_NEWLINE",
	"XT_COMMA",
	"XT_COLON",
	"XT_AMPERSAND",
	"XT_DOLLAR",
	"XT_L_RB",
	"XT_R_RB",
	"XT_L_SB",
	"XT_R_SB",

	"XT_WS",
	"XT_COMMENT",
	"XT_EOF",
};
std::string XirToken_Name(int token)
{
	FS_TRACE_ERROR_ON(token>=XT_TOKEN_NU,"Token(%d) Valied",token);
	return std::string(s_xir_token_name[token]);
}

