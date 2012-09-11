#include<vector3.h>

int add(int x,int y)
{
	Vector3 a(0,0,0);
	Vector3 b(1,1,1);
	Vector3 c=a.add(b);
	return x+y;
}

