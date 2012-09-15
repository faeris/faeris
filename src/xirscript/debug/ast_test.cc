#include"xir_scanner.h"
#include"xir_parser.h"
#include"xir_token.h"
#include"sl_state.h"
#include"xir_ast.h"
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

	XirAstNode* ret=XirParser::parse(f);
	if(ret!=NULL)
	{
		printf("Parse Success\n");
		printf("---------------------\n");
		XirAstNode_Print(ret,XirAstNode::DT_NEWLINE,true);

		printf("\n");
		printf("------------------------\n");
		XirAstNode_Print(ret,XirAstNode::DT_COMMA,false);
		printf("\n");
	}
	else
	{
		printf("Parse Failed\n");
	}

	if(ret)
	{
		delete ret;
	}
	f->close();
	delete f;
	return 0;
}

