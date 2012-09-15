%{
#include"xirscript/xir_scanner.h"
#include"xirscript/xir_parser.h"
%}

%token tUNKOWN tERR
%token tSIM_STR tDOU_STR tSIN_STR 
%token tNEWLINE tCOMMA 
%token tCOLON tAMPERSAND tDOLLAR
%token tL_RB tR_RB tL_SB tR_SB

%pure_parser
%start xir_start
%%

xir_start:ref_body dict_body ;
xir_start:delimiter ref_body dict_body;
xir_start:dict_body;

primity:dict | array | string | refer;
string:tSIM_STR | tDOU_STR | tSIN_STR;

refer:tDOLLAR tSIM_STR;

delimiter:tNEWLINE | tCOMMA ;

ref_body:tAMPERSAND tL_RB dict_body tR_RB;
ref_body:tAMPERSAND tL_RB tR_RB;

dict:tL_RB dict_body tR_RB ;
dict:tL_RB tR_RB ;

dict_body: delimiter
	|dict_body_real
	|dict_body_real delimiter
	|delimiter dict_body_real 
	|delimiter dict_body_real delimiter
;

dict_body_real:dict_entry
	|dict_body_real delimiter dict_entry
;

dict_entry: tSIM_STR tCOLON primity ;


array:tL_SB tR_SB;
array:tL_SB array_body tR_SB;

array_body:delimiter
	|array_body_real
	|array_body_real delimiter
	|delimiter array_body_real 
	|delimiter array_body_real delimiter
;

array_body_real:array_entry
	|array_body_real delimiter array_entry

;

array_entry:primity ;



