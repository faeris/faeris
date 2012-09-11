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

void id_array_create()
{
	memset(id_array,0,sizeof(id_array));
	id_array['\n']=SI_NEWLINE;
	id_array[',']=SI_COMMA;
	id_array[':']=SI_COLON;
	id_array['&']=SI_AMPERSAND;
	id_array['$']=SI_DOLLAR;
	id_array['{']=SI_L_RB;
	id_array['}']=SI_R_RB;
	id_array['[']=SI_L_SB;
	id_array[']']=SI_R_SB;
}


int main()
{
	id_array_create();
	print_array(id_array);
	return 0;
}
