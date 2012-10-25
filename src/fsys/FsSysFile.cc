#include"FsSysFile.h"

FAERIS_NAMESPACE_BEGIN
#if defined(FS_OS_WIN)||defined(FS_OS_LINUX)
	#include "platform/FsSysFileStdio.cc"
#else
	#error "Error Platform For SysFile"
#endif 
FAERIS_NAMESPACE_END
