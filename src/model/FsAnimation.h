#ifndef _FS_ANIMATION_H_
#define _FS_ANIMATION_H_ 
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
class Animation
{
	public:
		virtual void update(FsLong mesc);
		virtual void restart();
		virtual void pause();
		virtual void stop();
		virtual void setFps();
};
FAERIS_NAMESPACE_END 
#endif 

