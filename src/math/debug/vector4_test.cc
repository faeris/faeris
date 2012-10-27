#include <stdio.h>
#include"FsVector4.h"

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

using namespace Faeris;


int test_constructor()
{
	Vector4 v1(1,2,3,4);
	Vector4 v2(1,2,3);

	if(!(1==v1.x&&2==v1.y&&3==v1.z&&4==v1.w))
	{
		return 0;
	}
	if(!(1==v2.x&&2==v2.y&&3==v2.z&&1==v2.w))
	{
		return 0;
	}
	return 1;
}
	

int test_equal()
{
	Vector4 v1(1,2,3,4);
	Vector4 v2(1,2,3,4);
	Vector4 v3(1,3,4,5);

	if(!v1.equal(v2))
	{
		return 0;
	}

	if(v1.equal(v3))
	{
		return 0;
	}
	return 1;
}


int test_add()
{
	Vector4 v1(1,2,3,4);
	Vector4 v2(2,4,6,8);

	Vector4 r=v1.add(v2);


	if(!r.equal(Vector4(3,6,9,12)))
	{
		return 0;
	}
	return 1;
}

int test_sub()
{
	Vector4 v1(1,2,3,4);
	Vector4 v2(2,4,6,8);

	Vector4 r=v2.sub(v1);

	if(!r.equal(Vector4(1,2,3,4)))
	{
		return 0;
	}
	return 1;
}


int test_scale()
{
	Vector4 v(1,2,3,4);
	float k=3;

	Vector4 r=v.scale(k);

	if(!r.equal(Vector4(3,6,9,12)))
	{
		return 0;
	}
	return 1;
}


int test_dot()
{
	Vector4 v1(1,2,3,4);
	Vector4 v2(5,6,7,8);

	float r=v1.dot(v2);

	if(!Math::floatEqual(r,1*5+2*6+3*7+4*8))
	{
		return 0;
	}
	return 1;
}


int test_length()
{
	Vector4 v1(1,2,3,4);
	if(!Math::floatEqual(v1.length(),Math::sqrt(1*1+2*2+3*3+4*4)))
	{
		return 0;
	}
	return 1;
}




int test_normal()
{
	Vector4 v1(1,2,3,4);
	float l=v1.length();

	if(!v1.normal().equal(Vector4(1/l,2/l,3/l,4/l)))
	{
		return 0;
	}
	return 1;
}

int test_normalize()
{
	Vector4 v1(1,2,3,4);
	Vector4 v2=v1.normal();
	v1.normalize();

	if(!v1.equal(v2))
	{
		return 0;
	}
	return 1;
}


int g_corret=0;
int g_error=0;

int main()
{
	Func_Test(test_constructor);
	Func_Test(test_equal);
	Func_Test(test_add);
	Func_Test(test_sub);
	Func_Test(test_scale);
	Func_Test(test_dot);
	Func_Test(test_length);
	Func_Test(test_normal);
	printf("TestResult: Error(%d),Ok(%d)\n",g_error,g_corret);
	return 0;
}
