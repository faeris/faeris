#ifndef _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#define _FAERY_XIR_SCRIPT_XIR_PARSE_H_
//#include"xirscript/xir_ast.h"
#include"io/ifile.h"
#include"xirscript/xir_scanner.h"
class XirAst;
class XirParser
{
	public:
		static XirAst* parse(IFile* file);
};
class YYParserParm
{
	public:
		XirScanner* m_lex;
		XirAst* m_root;
		bool m_delimiter;
	public:
		YYParserParm(XirScanner* lex)
		{
			m_lex=lex;
			m_root=NULL;
			m_delimiter=false;
		}
};
#define YACC_SHIFT_BASE  258

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm

int yylex(void* lvap,void* parm);
int yyparse(void* parm);
void xir_parse_err(const char* ,void* YYPARSE_PARAM);

#define yyerror(msg)  xir_parse_err(msg,YYPARSE_PARAM)

#endif 

