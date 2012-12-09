#include "FsTimer.h"

#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsTimeLinux.cc"
#else 
	#error "Unsupport Platform OS"
#endif 
