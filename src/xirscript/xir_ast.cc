#include"xirscript/xir_ast.h"
#include<assert.h>
#include"FsMacros.h"

static void __XirAstNode_Print(XirAstNode* node,char demiliter,bool indent,int indent_nu);

static void Print_Indent(int num)
{
	for(int i=0;i<num;i++)
	{
		printf("  ");
	}
}

static void __XirAstRoot_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_ROOT);
	XirAstComplexNode* node=(XirAstComplexNode*)n;
	bool print_demiliter=false;

	for(int i=0;i<node->getChirldNum();i++)
	{

		XirAstComplexNode* c=(XirAstComplexNode*)(node->getChirld(i));
		int type=c->getType();
		switch(type)
		{

			case XirAstNode::AT_REF_DICT:

				__XirAstNode_Print(c,demiliter,indent,indent_num);
				break;
			case XirAstNode::AT_DICT:
				int j=0;
				if(j<c->getChirldNum())
				{
					XirAstNode* cc=c->getChirld(j);
					__XirAstNode_Print(cc,demiliter,indent,indent_num);
					j++;
				}
	
				for(;j<c->getChirldNum();j++)
				{
					if(demiliter==XirAstNode::DT_NEWLINE)
					{
						printf("\n");
					}
					else
					{
						printf(",");
					}
					XirAstNode* cc=c->getChirld(j);
					__XirAstNode_Print(cc,demiliter,indent,indent_num);
				}
				break;
		}
		if(!print_demiliter&&node->getChirldNum()==2)
		{
			if(demiliter==XirAstNode::DT_NEWLINE)
			{
				printf("\n");
			}
			else
			{
				printf(",");
			}
		}


	}

}

static void __XirAstRefDict_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_REF_DICT);
	XirAstComplexNode* node=(XirAstComplexNode*)n;
	if(indent)
	{
		Print_Indent(indent_num);
	}
	printf("&{");
	if(demiliter==XirAstNode::DT_NEWLINE)
	{
		printf("\n");
	}
	int i=0;
	if(i<node->getChirldNum())
	{
		XirAstNode* c=node->getChirld(i);
		__XirAstNode_Print(c,demiliter,indent,indent_num+1);
		i++;
	}
	for(;i<node->getChirldNum();i++)
	{
		if(demiliter==XirAstNode::DT_NEWLINE)
		{
			printf("\n");
		}
		else
		{
			printf(",");
		}
		XirAstNode* c=node->getChirld(i);
		__XirAstNode_Print(c,demiliter,indent,indent_num+1);

	}
	if(demiliter==XirAstNode::DT_NEWLINE)
	{
		printf("\n");

		if(indent)
		{
			Print_Indent(indent_num);
		}
	}
	printf("}");
}

static void __XirAstDict_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_DICT);
	XirAstComplexNode* node=(XirAstComplexNode*)n;
	printf("{");
	if(demiliter==XirAstNode::DT_NEWLINE)
	{
		printf("\n");
	}
	int i=0;
	if(i<node->getChirldNum())
	{
		XirAstNode* c=node->getChirld(i);
		__XirAstNode_Print(c,demiliter,indent,indent_num+1);
		i++;
	}
	for(;i<node->getChirldNum();i++)
	{
		if(demiliter==XirAstNode::DT_NEWLINE)
		{
			printf("\n");
		}
		else
		{
			printf(",");
		}
		XirAstNode* c=node->getChirld(i);
		__XirAstNode_Print(c,demiliter,indent,indent_num+1);

	}
	if(demiliter==XirAstNode::DT_NEWLINE)
	{
		printf("\n");
		if(indent)
		{
			Print_Indent(indent_num-1);
		}
	}
	printf("}");
}
static void __XirAstArray_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_ARRAY);
	XirAstComplexNode* node=(XirAstComplexNode*)n;
	printf("[");
	if(demiliter==XirAstNode::DT_NEWLINE)
	{
		printf("\n");
	}
	int i=0;
	if(i<node->getChirldNum())
	{
		if(demiliter==XirAstNode::DT_NEWLINE)
		{
			if(indent)
			{
				Print_Indent(indent_num);
			}
		}
		XirAstNode* c=node->getChirld(i);
		__XirAstNode_Print(c,demiliter,indent,indent_num+1);
		i++;
	}
	for(;i<node->getChirldNum();i++)
	{
		if(demiliter==XirAstNode::DT_NEWLINE)
		{
			printf("\n");
		}
		else
		{
			printf(",");
		}
		if(indent)
		{
			Print_Indent(indent_num);
		}
		XirAstNode* c=node->getChirld(i);
		__XirAstNode_Print(c,demiliter,indent,indent_num+1);

	}
	if(demiliter==XirAstNode::DT_NEWLINE)
	{
		printf("\n");
		if(indent)
		{
			Print_Indent(indent_num-1);
		}
	}
	printf("]");
}

static void __XirAstString_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_STRING);
	XirAstStringNode* node=(XirAstStringNode*)n;
	printf("%s",node->getString().c_str());
}
static void __XirAstRefer_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_REFER);
	XirAstStringNode* node=(XirAstStringNode*)n;
	printf("$%s",node->getString().c_str());
}

static void __XirAstDictEntry_Print( XirAstNode* n,int demiliter,bool indent,int indent_num)
{
	assert(n->getType()==XirAstNode::AT_DICT_ENTRY);
	XirAstComplexNode* node=(XirAstComplexNode*)n;

	assert(node->getChirldNum()==2);

	if(indent)
	{
		Print_Indent(indent_num);
	}
	XirAstNode* n1=node->getChirld(0);
	XirAstNode* n2=node->getChirld(1);

	__XirAstNode_Print(n1,demiliter,indent,indent_num+1);
	printf(":");
	__XirAstNode_Print(n2,demiliter,indent,indent_num+1);
}




static void __XirAstNode_Print(XirAstNode* node,char demiliter,bool indent,int indent_num)
{
	int type=node->getType();
	switch(type)
	{
		case XirAstNode::AT_ROOT:
			__XirAstRoot_Print((XirAstComplexNode*)node,demiliter,indent,indent_num);
			break;
		case XirAstNode::AT_REF_DICT:
			__XirAstRefDict_Print((XirAstComplexNode*)node,demiliter,indent,indent_num);
			break;
		case XirAstNode::AT_DICT:
			__XirAstDict_Print((XirAstComplexNode*)node,demiliter,indent,indent_num);
			break;
		case XirAstNode::AT_ARRAY:
			__XirAstArray_Print((XirAstComplexNode*)node,demiliter,indent,indent_num);
			break;
		case XirAstNode::AT_STRING:
			__XirAstString_Print((XirAstStringNode*)node,demiliter,indent,indent_num);
			break;
		case XirAstNode::AT_DICT_ENTRY:
			__XirAstDictEntry_Print((XirAstComplexNode*)node,demiliter,indent,indent_num);
			break;
		case XirAstNode::AT_REFER:
			__XirAstRefer_Print((XirAstReferNode*)node,demiliter,indent,indent_num);
			break;
		default:
			FS_TRACE_ERROR("Unkown Type(%d)",type);
	}
}





void XirAstNode_Print(XirAstNode* node,int demiliter,bool indent)
{

	__XirAstNode_Print(node,demiliter,indent,0);
}
//	int XirAstNode_Check(XirAstNode* node);

