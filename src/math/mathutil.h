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

#ifndef PI 
#define PI 3.1415926f
#endif 

#endif 

