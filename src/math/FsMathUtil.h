#ifndef FY_MATH_MATH_UTIL_H_
#define FY_MATH_MATH_UTIL_H_
#include <math.h>
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
FS_BEGIN_NAMESPACE(Math)
#ifndef FS_PI 
#define FS_PI 3.1415926f
#endif 

inline float radianToAngle(float radian)
{
	return radian/FS_PI*180.0f;
}
inline float angleToRadian(float  angle)
{
	return angle/180.0f*FS_PI;
}

inline float cosr(float radian){return ::cos(radian);}
inline float sinr(float radian){return ::sin(radian);}
inline float tanr(float radian){return ::tan(radian);}
inline float acosr(float radian){return ::acos(radian);}

inline float cosa(float angle){return ::cos(angleToRadian(angle));}
inline float sina(float angle){return ::sin(angleToRadian(angle));}
inline float tana(float angle){return ::tan(angleToRadian(angle));}
inline float acosa(float angle){return ::acos(angleToRadian(angle));}

inline float sqrt(float v){return ::sqrt(v);}

template<typename T> T abs(T f){return f<0?-f:f;}

FsVoid srand(FsUlong s);
FsInt random();
FsInt random(FsInt begin,FsInt end);

inline FsInt floatEqual(float a,float b)
{
	return abs(a-b)<0.0001?1:0;
}

FS_END_NAMESPACE(Math)



FAERIS_NAMESPACE_END

#endif 

