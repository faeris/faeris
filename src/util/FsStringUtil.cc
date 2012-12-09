#include "FsStringUtil.h"

FAERIS_NAMESPACE_BEGIN
FsUlong FsUtil_JStringHashCode(const char* str)
{
	FsUlong hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return hash ;
}
FAERIS_NAMESPACE_END

