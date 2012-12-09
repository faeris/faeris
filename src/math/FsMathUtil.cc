#include <math.h>
#include <stdlib.h>

#include "FsMathUtil.h"

FAERIS_NAMESPACE_BEGIN

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
