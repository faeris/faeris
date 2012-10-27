#include"FsSysFile.h"

#if FS_PLATFORM_OS(FS_OS_WIN)|| FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsSysFileStd.cc"
#else
	#error "Error Platform For SysFile"
#endif 
