#ifndef _FAERIS_RENDER_TARGET_H_
#define _FAERIS_RENDER_TARGET_H_
#include "FsMacros.h"
#include "core/FsObject.h"
FAERIS_NAMESPACE_BEGIN
class RenderTarget:FsObject
{
	public:
		RenderTarget* create
	public:
		virtual void flush();
		virtual void swapBuffer();

};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_RENDER_TARGET_H_*/

