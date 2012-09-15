%{
#include"xirscript/xir_scanner.h"
#include"xirscript/xir_parser.h"

#define CAST_PARAM  ((YYParserParm*) YYPARSE_PARAM)
#define YYSTYPE XirAstNode* 
%}

%token tUNKOWN tERR
%token tSIM_STR tDOU_STR tSIN_STR 
%token tNEWLINE tCOMMA 
%token tCOLON tAMPERSAND tDOLLAR
%token tL_RB tR_RB tL_SB tR_SB

%pure_parser
%start xir_start
%%

xir_start:ref_body dict_body 
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_ROOT);
		node->addChrild($1);
		node->addChrild($2);
		$$=node;
		CAST_PARAM->setRoot(node);
	}
	|delimiter ref_body dict_body
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_ROOT);
		node->addChrild($2);
		node->addChrild($3);
		$$=node;
		CAST_PARAM->setRoot(node);
	}
	|dict_body
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_ROOT);
		node->addChrild($1);
		$$=node;
		CAST_PARAM->setRoot(node);
	}
;

primity:dict{$$=$1;}
	| array {$$=$1;}
	| string {$$=$1;}
	| refer{$$=$1;}
;

string:tSIM_STR 
	{
		$$=CAST_PARAM->newStringNode();
	}
	| tDOU_STR
	{
		$$=CAST_PARAM->newStringNode();
	}
	| tSIN_STR
	{
		$$=CAST_PARAM->newStringNode();
	}
;

sim_str:tSIM_STR
	{
		$$=CAST_PARAM->newStringNode();
	}
refer:tDOLLAR tSIM_STR
{
	$$=CAST_PARAM->newReferNode();
}
;	 

delimiter:tNEWLINE | tCOMMA ;

ref_body:tAMPERSAND tL_RB tR_RB	
	{
		$$=CAST_PARAM->newComplexNode(XirAstNode::AT_REf_DICT);
	}
	|tAMPERSAND tL_RB dict_body tR_RB
	{
		XirAstComplexNode* node=(XirAstComplexNode*)($3);
		node->setType(XirAstNode::AT_REf_DICT);
		$$=node;
	}
;

dict:tL_RB tR_RB 
	{	
		$$=CAST_PARAM->newComplexNode(XirAstNode::AT_DICT);
	}
	|tL_RB dict_body tR_RB 
	{
		$$=$2;
	}
;

dict_body: delimiter 
	{
		$$=CAST_PARAM->newComplexNode(XirAstNode::AT_DICT);
	}
	|dict_body_real{$$=$1;}
	|dict_body_real delimiter{$$=$1;}
	|delimiter dict_body_real{$$=$2;}
	|delimiter dict_body_real delimiter{$$=$2;}
;

dict_body_real:dict_entry
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_DICT);
		node->addChrild($1);
		$$=node;
	}
	|dict_body_real delimiter dict_entry
	{
		XirAstComplexNode* node=(XirAstComplexNode*)($1);
		node->addChrild($3);
		$$=node;
	}
;

dict_entry: sim_str tCOLON primity 
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_DICT_ENTRY);
		node->addChrild($1);
		node->addChrild($3);
		$$=node;
	}
;


array:tL_SB tR_SB
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_ARRAY);
		$$=node;
	}
	|tL_SB array_body tR_SB{$$=$2;}
;

array_body:delimiter
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_ARRAY);
		$$=node;
	}
	|array_body_real{$$=$1;}
	|array_body_real delimiter{$$=$1;}
	|delimiter array_body_real {$$=$2;}
	|delimiter array_body_real delimiter{$$=$2;}
;

array_body_real:array_entry
	{
		XirAstComplexNode* node=CAST_PARAM->newComplexNode(XirAstNode::AT_ARRAY);
		node->addChrild($1);
		$$=node;
	}

	|array_body_real delimiter array_entry
	{
		XirAstComplexNode* node=(XirAstComplexNode*)($1);
		node->addChrild($3);
		$$=node;
	}

;

array_entry:primity {$$=$1;}
;



