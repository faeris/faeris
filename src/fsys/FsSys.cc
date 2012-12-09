#include "fsys/FsSys.h"
#include "FsConfig.h"
#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsSysLinux.cc"
#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/

