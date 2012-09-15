#include"xir_scanner.h"
#include"xir_parser.h"
#include"xir_token.h"
#include"sl_state.h"
#include"io/sys_file.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("usage: %s <file>\n",argv[0]);
		exit(-1);
	}

	SysFile* f=SysFile::open(argv[1],"rb");
	if(f==NULL)
	{
		printf("Open File(%s) Failed\n",argv[1]);
		exit(-1);
	}

	XirScanner* s=new XirScanner(f,&Xir_Top);
	YYParserParm* pm=new YYParserParm(s);


	while(1)
	{

		int token=yylex(NULL,pm);
		if(token==EOF)
		{
			break;
		}
		printf("%d:%s:<%s>\n",pm->m_lex->curLine(),
				XirToken_Name(token-YACC_SHIFT_BASE).c_str(),
				pm->m_lex->curString().c_str());
	}
	delete s;
	delete f;
	delete pm;
	return 0;
}

	

