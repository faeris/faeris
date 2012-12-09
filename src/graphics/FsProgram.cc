#include "graphics/FsProgram.h"
#if FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLProgram.cc"
#else 
	#error "Unsupport PlatformProgram"
#endif 
