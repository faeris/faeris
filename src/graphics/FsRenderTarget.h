#ifndef _FAERIS_RENDER_TARGET_H_
#define _FAERIS_RENDER_TARGET_H_
#include "FsMacros.h"
#include "core/FsObject.h"
FAERIS_NAMESPACE_BEGIN
class Render;
class RenderTarget:FsObject
{
	public:
		virtual void swapBuffers()=0;
		virtual void makeCurrent(Render*)=0;
		virtual void loseCurrent(Render*)=0;
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_RENDER_TARGET_H_*/

