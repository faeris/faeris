#include <FsVector3.h>
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
	Vector3 v(1,2,3);
	if(v.x!=1)
	{
		return 0;
	}
	if(v.y!=2)
	{
		return 0;
	}
	if(v.z!=3)
	{
		return 0;
	}
	return 1;
}
int test_equal()
{
	Vector3 v1(1,2,3);
	Vector3 v2(1,2,3);
	Vector3 v3(2,4,6);

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
	Vector3 v1(1,2,3);
	Vector3 v2(1,2,3);
	Vector3 r=v1.add(v2);
	if(!r.equal(Vector3(2,4,6)))
	{
		return 0;
	}
	return 1;
}
int test_sub()
{
	Vector3 v1(2,8,16);
	Vector3 v2(1,2,3);
	Vector3 r=v1.sub(v2);

	if(!r.equal(Vector3(1,6,13)))
	{
		return 0;
	}
	return 1;
}

int test_scale()
{
	Vector3 v1(1,2,3);
	Vector3 r=v1.scale(3);

	if(!r.equal(Vector3(3,6,9)))
	{
		return 0;
	}
	return 1;
}

int test_dot()
{
	Vector3 v1(1,2,3);
	Vector3 v2(2,4,6);

	float r=v1.dot(v2);
	if(r!=28)
	{
		return 0;
	}
	return 1;
}


int test_cross()
{
	Vector3 v1(1,2,3);
	Vector3 v2(2,4,6);
	Vector3 r=v1.cross(v2);

	if(Math::abs(r.dot(v1))>0.00001)
	{
		return 0;
	}
	if(Math::abs(r.dot(v2))>0.00001)
	{
		return 0;
	}
	return 1;
}

int test_length()
{
	Vector3 v(3,4,5);

	float l=Math::sqrt(3*3+4*4+5*5);

	if(Math::floatEqual(v.length(),l))
	{
		return 1;
	}
	return 0;
}

int test_normal()
{
	Vector3 v1(100,100,100);

	if(!Math::floatEqual(v1.normal().length(),1))
	{
		return 0;
	}

	Vector3 v2(3,4,5);

	float l=v2.length();

	if(!v2.normal().equal(Vector3(3/l,4/l,5/l)))
	{
		return 0;
	}

	return 1;
}

int test_normalize()
{
	Vector3 v1(10,142,13);
	Vector3 r=v1.normal();

	v1.normalize();

	if(!v1.equal(r))
	{
		return 0;
	}

	return 0;
}


int test_project()
{
	Vector3 v1(2,2,2);
	Vector3 v2(1,1,1);
	if(!v1.proj(v2).equal(Vector3(2,2,2)))
	{
		//v1.proj(v2).print();
		return 0;
	}
	if(!v2.proj(v1).equal(Vector3(1,1,1)))
	{
		//v2.proj(v1).print();
		return 0;
	}

	Vector3 v3(1,1,0);


	if(!v3.proj(v1).equal(Vector3(2.0/3,2.0/3,2.0/3)))
	{
		//v3.proj(v1).print();
		return 0;
	}


	Vector3 v4(8.3,-9.2,1.3);
	Vector3 v5(-3.5,3.3,9.5);

	Vector3 vp=v4.proj(v5);
	Vector3 vq=v4.sub(vp);

	if (!Math::floatEqual(vp.dot(vq),0))
	{
		printf("%.10f\n",vp.dot(vq));
		return 0;
	}


	return 1;
}
int test_angle()
{
	Vector3 v1(1,1,1);
	Vector3 v2(2,2,2);
	Vector3 v3(3,3,0);

	if( !Math::floatEqual(v1.angle(v2),0))
	{
		return 0;
	}
	if(!Math::floatEqual(v1.angle(v3),35.264389))
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
	Func_Test(test_cross);
	Func_Test(test_length);
	Func_Test(test_normal);
	Func_Test(test_project);
	Func_Test(test_angle);



	printf("TestResult: Error(%d),Ok(%d)\n",g_error,g_corret);
	return 0;
}























