/******************************************
 * File: mathutil.h
 * Description:
 * Author: NosicLin(nosiclin@foxmail.com)
 * Date:2012-9-13
 * LastUpdate:2012-9-28
 * Copyright:Faery Studio
 ******************************************/
#ifndef FY_MATH_MATH_UTIL_H_
#define FY_MATH_MATH_UTIL_H_
#include<float.h>

static inline float float_abs(float x)
{
	return x<0?-x:x;
}
static inline float float_equal(float x,float y)
{
	float diff=x-y;
	return float_abs(diff)<0.00001;
}

class Math 
{
	public:
		static float cos(float angle);
		static float sin(float angle);
		static float tan(float angle);
		static float abs(float f){return f<0?-f:f;}
		static void srand(unsigned long s);
		static int random();
		static int random(int begin,int end);
		static int floatEqual(float a,float b)
		{
			return abs(a-b)<0.0001?1:0;
		}
};
#ifndef PI 
#define PI 3.1415926f
#endif 

#endif 

