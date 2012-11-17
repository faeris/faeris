#include<stdio.h>
#include"xirscript/xir_token.h"
#include"xirscript/sl_state.h"

#include"xirscript/xir_parser.h"
#define YYACCEPT 0

int yylex(void* lvap,void* parm)
{
	YYParserParm* pm=(YYParserParm*)parm;
	XirScanner* l=pm->m_lex;
	int token;
	while(1)
	{
		token=l->nextToken();
		if(token==XT_COMMENT)
		{
			token=XT_NEWLINE;
		}
		else if(token==XT_WS)
		{
			continue;
		}
		else if(token==XT_EOF)
		{
			return EOF;
		}
		if(token==XT_NEWLINE||token==XT_COMMA)
		{
			if(pm->m_delimiter)
			{
				continue;
			}
			pm->m_delimiter=true;
		}
		else
		{
			pm->m_delimiter=false;
		}
		break;
	}

	return token+YACC_SHIFT_BASE;
}
void xir_parse_err(const char* msg,void* parm)
{
	YYParserParm* pm=(YYParserParm*)parm;
	XirScanner* l=pm->m_lex;
	
	int line=l->curLine();
	printf("yyerror:At Line(%d)\n",line);

}

XirAstNode* XirParser::parse(IFile* file)
{
	XirScanner* lex=new XirScanner(file,&Xir_Top);
	YYParserParm* parm=new YYParserParm(lex);
	int ret=yyparse(parm);
	if(ret!=YYACCEPT)
	{
		delete lex;
		parm->deletePendingNode();
		delete parm;
		return NULL;
	}

	delete lex;
	XirAstNode* ast=parm->getRoot();
	FS_TRACE_ERROR_ON(ast==NULL,"Some Error Must Happened In xir_grammy.y");
	delete parm;
	return ast;
}
