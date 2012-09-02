#include"grstring.h"
#include<stdio.h>
#include<string.h>
void print_string(const GrString& str)
{
	printf("%s",str.c_str());
}
	
#define Func_Test(func) \
	do{ \
		printf("Unit_Test(%s)---",#func); \
		int ret; \
		ret=func(); \
		if(ret) \
		{  \
			printf("(Ok)"); \
			g_corret++; \
		} \
		else \
		{  \
			printf("(Falied)");  \
			g_error++; \
		} \
		printf("\n"); \
	} while(0) 


int test_constructor()
{
	char str[]="hello world";
	GrString s(str);
	if(strcmp(s.c_str(),str)!=0)
	{
		return 0;
	}
	return 1;
}
int test_compare()
{
	GrString s1("aaaa");
	GrString s2("bbbb");
	GrString s3("cccc");
	GrString s4("bbbb");
	if(s1.compare(s2)>=0)
	{
		return 0;
	}
	if(s2.compare(s1)<=0)
	{
		return 0;
	}
	if(s2.compare(s3)>=0)
	{
		return 0;
	}
	if(s3.compare(s2)<=0)
	{
		return 0;
	}
	if(s4.compare(s2)!=0)
	{
		return 0;
	}
	return 1;
}


int test_append()
{
	char str_hello[]="hello";
	char str_world[]="world";
	GrString s;
	s.append(str_hello);
	s.append(" ");
	s.append(str_world);

	if(s.compare("hello world")!=0)
	{
		return 0;
	}

	GrString s2("hh");
	s2.append("aaaaa",2);
	if(s2.compare("hhaa")!=0)
	{
		return 0;
	}

	GrString s3("hh");
	GrString s4("aaaaa");
	s3.append(s4,2);
	if(s3.compare("hhaa")!=0)
	{
		return 0;
	}
	
	return 1;
}

int g_error=0;
int g_corret=0;

int main()
{
	Func_Test(test_constructor);
	Func_Test(test_compare);
	Func_Test(test_append);
	printf("Test Result All(%d) Correct(%d) Failed(%d)\n",
			g_error+g_corret,g_corret,g_error);
	return 0;
}















