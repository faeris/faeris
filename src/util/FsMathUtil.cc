#include <math.h>
#include <stdlib.h>

#include "FsMathUtil.h"

FAERIS_NAMESPACE_BEGIN
FsFloat Math::cos(FsFloat angle)
{
	return ::cos(angle);
}
FsFloat Math::sin(FsFloat angle)
{
	return ::sin(angle);
}
FsFloat Math::tan(FsFloat angle)
{
	return ::tan(angle);
}
FsFloat Math::acos(FsFloat v)
{
	return ::acos(v);
}


FsFloat Math::sqrt(FsFloat v)
{
	return ::sqrt(v);
}


FsVoid Math::srand(FsUlong s)
{
	::srand(s);
}

FsInt Math::random()
{
	return ::rand();
}
FsInt Math::random(FsInt begin,FsInt end)
{
	return begin+::rand()%(end-begin);
}

FAERIS_NAMESPACE_END
