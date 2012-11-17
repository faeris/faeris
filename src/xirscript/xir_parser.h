#ifndef _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#define _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#include"xirscript/xir_ast.h"
#include"fsys/FsFile.h"
#include"xirscript/xir_scanner.h"
#include<vector>
class XirParser
{
	public:
		static XirAstNode* parse(Faeris::FsFile* file);
};
class YYParserParm
{
	public:
		XirScanner* m_lex;
		XirAstNode* m_root;
		bool m_delimiter;
		std::vector<XirAstNode*> m_pending_node;
	public:
		YYParserParm(XirScanner* lex)
		{
			m_lex=lex;
			m_root=NULL;
			m_delimiter=false;
		}
		void deletePendingNode()
		{
			unsigned long size=m_pending_node.size();
			for(unsigned int i=0;i<size;i++)
			{
				m_pending_node[i]->deleteSelf();
			}
			m_pending_node.clear();
		}
		XirAstStringNode* newStringNode()
		{
			int line=m_lex->curLine();
			XirAstStringNode* node=new XirAstStringNode(m_lex->curString(),line);
			m_pending_node.push_back(node);
			return node;
		}
		XirAstReferNode* newReferNode()
		{
			int line=m_lex->curLine();
			XirAstReferNode* node=new XirAstReferNode(m_lex->curString(),line);
			m_pending_node.push_back(node);
			return node;
		}

		XirAstComplexNode* newComplexNode(int type)
		{
			int line=m_lex->curLine();
			XirAstComplexNode* node=new XirAstComplexNode(type,line);
			m_pending_node.push_back(node);
			return node;
		}

		void setRoot(XirAstNode* root)
		{
			m_root=root;
		}
		XirAstNode* getRoot()
		{
			return m_root;
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

