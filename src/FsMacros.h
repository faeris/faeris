#ifndef _FAERIS_MACROS_H_
#define _FAERIS_MACROS_H_
#include "FsTypes.h"

#define FS_BEGIN_NAMESPACE(name) namespace name{
#define FS_END_NAMESPACE(name) }

#define FAERIS_NAMESPACE_BEGIN FS_BEGIN_NAMESPACE(Faeris)
#define FAERIS_NAMESPACE_END  FS_END_NAMESPACE(Faeris)

#define FS_PLATFORM_OS defined

#define FS_OS_LINUX

#ifndef NULL
	#define NULL 0
#endif 

#define FS_WARN_ON(cnd,fmt,...)
#define FS_BUG_ON(cnd,fmt,...)
#define FS_DEBUG_ON(cnd,fmt,...)

#define FS_WARN(fmt,...)
#define FS_BUG(fmt,...)
#define FS_DEBUG(fmt,...)

#endif /*_FAERIS_MACROS_H_*/

