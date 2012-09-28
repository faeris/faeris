/******************************************
 * File: math.cc
 * Description:
 * Author: NosicLin(nosiclin@foxmail.com)
 * Date:2012-9-28
 * LastUpdate:2012-9-28
 * Copyright:Faery Studio
 ******************************************/
#include<math.h>
#include"core/mathutil.h"
#include"stdlib.h"

float Math::cos(float angle)
{
	return ::cos(angle);
}
float Math::sin(float angle)
{
	return ::sin(angle);
}
float Math::tan(float angle)
{
	return ::tan(angle);
}

void Math::srand(unsigned long s)
{
	::srand(s);
}

int Math::random()
{
	return ::rand();
}
int Math::random(int begin,int end)
{
	return begin+::rand()%(end-begin);
}


