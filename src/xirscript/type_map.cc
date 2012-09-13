#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define ASSIC_NUM 256
char id_array[ASSIC_NUM];
void print_array(char* array)
{
	int i;
	for(i=0;i<ASSIC_NUM;i++)
	{
		if(i%32==0&&i!=0)
		{
			printf("\n");
		}
		if(i!=ASSIC_NUM-1)
		{
			printf("%d,",array[i]);
		}
		else
		{
			printf("%d\n",array[i]);

		}
	}
}

enum Sim_Str_Input_Type
{
	SS_ERR=0,
	SS_NORMAL,
	SS_WS,	
};

enum  Double_Str_Input_Type
{
	DS_ERR=0,
	DS_SLASH=1,
	DS_QUOTE=2,
};

enum  Specific_Input_type
{
	SI_OTHER=0,
	SI_NEWLINE,
	SI_COMMA,
	SI_COLON,
	SI_AMPERSAND,
	SI_DOLLAR,
	SI_L_RB,
	SI_R_RB,
	SI_L_SB,
	SI_R_SB,
};

enum Xir_Top_Input_Type
{
	XP_OTHER=0,
	XP_NEWLINE,
	XP_COMMA,
	XP_COLON,
	XP_AMPERSAND,
	XP_DOLLAR,
	XP_L_RB,
	XP_R_RB,
	XP_L_SB,
	XP_R_SB,
	XP_COMMENT,
	XP_WS,
	XP_LETTER,
	XP_SIN_QUOTE,
	XP_DOU_QUOTE,
};
void id_array_create()
{
	memset(id_array,0,sizeof(id_array));
	id_array['\n']=XP_NEWLINE;
	id_array[',']=XP_COMMA;
	id_array[':']=XP_COLON;
	id_array['&']=XP_AMPERSAND;
	id_array['$']=XP_DOLLAR;
	id_array['{']=XP_L_RB;
	id_array['}']=XP_R_RB;
	id_array['[']=XP_L_SB;
	id_array[']']=XP_R_SB;
	id_array['#']=XP_COMMENT;
	id_array[' ']=XP_WS;
	id_array['\t']=XP_WS;

	char c;
	for(c='0';c<='9';c++)
	{
		id_array[c]=XP_LETTER;
	}
	for(c='a';c<='z';c++)
	{
		id_array[c]=XP_LETTER;
	}
	for(c='A';c<='Z';c++)
	{
		id_array[c]=XP_LETTER;
	}

	id_array['\'']=XP_SIN_QUOTE;
	id_array['\"']=XP_DOU_QUOTE;
}



int main()
{
	id_array_create();
	print_array(id_array);
	return 0;
}
