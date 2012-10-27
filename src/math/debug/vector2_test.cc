#include<stdio.h>
#include<FsVector2.h>

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
	Vector2 v(1,2);
	if((1==v.x)&&(2==v.y))
	{
		return 1;
	}
	return 0;
}

int test_equal()
{
	Vector2 v1(1,2);
	Vector2 v2(3,4);
	Vector2 v3(3,4);

	if(v1.equal(v2))
	{
		return 0;
	}
	if(!v2.equal(v3))
	{
		return 0;
	}
	return 1;
}

int test_add()
{
	Vector2 v1(1,2);
	Vector2 v2(2,4);

	Vector2 r=v1.add(v2);
	if(!r.equal(Vector2(3,6)))
	{
		return 0;
	}
	return 1;
}

int test_sub()
{
	Vector2 v1(3,4);
	Vector2 v2(1,3);

	Vector2 r=v1.sub(v2);

	if(!r.equal(Vector2(2,1)))
	{
		return 0;
	}
	return 1;
}


int test_scale()
{
	Vector2 v1(1,2);
	float k=3;
	Vector2 r=v1.scale(k);
	if(!r.equal(Vector2(3,6)))
	{
		return 0;
	}
	return 1;
}


int test_dot()
{
	Vector2 v1(3,6);
	Vector2 v2(1,3);


	if(!Math::floatEqual(v1.dot(v2),21))
	{
		return 0;
	}
	return 1;
}


int test_length()
{
	Vector2 v1(3,4);

	if(!Math::floatEqual(v1.length(),5))
	{
		return 0;
	}
	return 1;
}

int test_normal()
{
	Vector2 v1(30,53);
	float l=v1.length();

	if(!v1.normal().equal(Vector2(30/l,53/l)))
	{
		return 0;
	}
	return 1;
}


int test_normalize()
{
	Vector2 v1(3,4);

	Vector2 v2=v1.normal();
	v1.normalize();

	if(!v1.equal(v2))
	{
		return 0;
	}
	return 1;
}



int test_project()
{
	Vector2 v1(2,2);
	Vector2 v2(1,1);

	if(!v1.proj(v2).equal(Vector2(2,2)))
	{
		return 0;
	}
	if(!v2.proj(v1).equal(Vector2(1,1)))
	{
		return 0;
	}

	Vector2 v3(3.45,8.1);
	Vector2 v4(-3.4,9.3);

	Vector2 vp=v4.proj(v3);
	Vector2 vq=v4.sub(vp);

	if(!Math::floatEqual(vp.dot(vq),0))
	{
		return 0;
	}
	return 1;
}


		

int test_angle()
{
	Vector2 v1(1,1);
	Vector2 v2(2,0);

	if(!Math::floatEqual(v1.angle(v2),45))
	{
		printf("%f\n",v1.angle(v2));
		return 0;
	}

	Vector2 v3(Math::cos(30.0/180*PI),Math::sin(30.0/180*PI));
	Vector2 v4(Math::cos(60.0/180*PI),Math::sin(60.0/180*PI));

	if(!Math::floatEqual(v3.angle(v4),30))
	{
		printf("%f\n",v3.angle(v4));
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
	Func_Test(test_project);
	Func_Test(test_angle);

	printf("TestResult: Error(%d),Ok(%d)\n",g_error,g_corret);
	return 0;
}













