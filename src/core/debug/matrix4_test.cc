#include"core/matrix4.h"
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


Matrix4 random_matrix()
{
	Matrix4 m;
	for(int i=0;i<16;i++)
	{
		m.v[i]=Math::random(0,100);
	}
	return m;
}

void matrix_print(const Matrix4& m)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%f ",m.v[i*4+j]);
		}
		printf("\n");
	}
}


int matrix4_equal(const Matrix4& l,const Matrix4& r)
{
	for(int i=0;i<16;i++)
	{
		if (!Math::floatEqual(l.v[i],r.v[i]))
		{
			return 0;
		}
	}
	return 1;
}
int  test_constructor()
{
	Matrix4 m(0,1,2,3,
			  4,5,6,7,
			  8,9,10,11,
			  12,13,14,15);

	for(int i=0;i<16;i++)
	{
		if(m.v[i]!=i)
		{
			return 0;
		}
	}
	return 1;
}

int test_add()
{
	Matrix4 m1=random_matrix();
	Matrix4 m2=random_matrix();
	
	Matrix4 r=m1;
	r.add(m2);

	for(int i=0;i<16;i++)
	{
		if(!Math::floatEqual(r.v[i],m1.v[i]+m2.v[i]))
		{
			return 0;
		}
	}
	return 1;
}

int test_mulScale()
{
	Matrix4 m=random_matrix();
	Matrix4 r=m;
	int s=Math::random(0,100);

	r.mulScaler(s);
	
	/*
	matrix_print(r);
	matrix_print(m);

	printf("Scale:%d\n",s);
	*/

	for(int i=0;i<16;i++)
	{
		if(!Math::floatEqual(m.v[i]*s,r.v[i]))
		{
			return 0;
		}
	}
	return 1;
}




int g_corret=0;
int g_error=0;



int main()
{
	Func_Test(test_constructor);
	Func_Test(test_add);
	Func_Test(test_mulScale);
	printf("TestResult: Error(%d),Ok(%d)\n",g_error,g_corret);
	return 0;
}
