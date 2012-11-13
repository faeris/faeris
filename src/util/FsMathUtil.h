#ifndef FY_MATH_MATH_UTIL_H_
#define FY_MATH_MATH_UTIL_H_
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
FS_BEGIN_NAMESPACE(Math)

FsFloat cos(FsFloat angle);
FsFloat sin(FsFloat angle);
FsFloat tan(FsFloat angle);
FsFloat acos(FsFloat v);

FsFloat sqrt(FsFloat v);

template<typename T> T abs(T f){return f<0?-f:f;}

FsVoid srand(FsUlong s);
FsInt random();
FsInt random(FsInt begin,FsInt end);

inline FsInt floatEqual(FsFloat a,FsFloat b)
{
	return abs(a-b)<0.0001?1:0;
}

FS_END_NAMESPACE(Math)


#ifndef PI 
#define PI 3.1415926f
#endif 

FAERIS_NAMESPACE_END

#endif 

