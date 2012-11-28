#include "core/FsWindow.h"

#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsWindowLinux.cc"
#else 
	#error "Unsupport Platform OS"
#endif 
	
