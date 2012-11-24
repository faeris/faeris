#include "graphics/FsShader.h"
#if FS_CONFIG(FS_GL_RENDER)	
	#include "platform/FsGLShader.cc"
#else 
	#error "Unsupport PlatformShader"
#endif /*FS_GL_RENDER*/

