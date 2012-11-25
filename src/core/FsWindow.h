#ifndef _FAERIS_WINDOW_H_
#define _FAERIS_WINDOW_H_ 
#include "FsMacros.h"
#include "graphics/FsRenderTarget.h"


FAERIS_NAMESPACE_BEGIN
class Window
{
	public:
		static Window* create(FsInt width,FsInt height,FsInt posx,FsInt posy,FsLong flags);
	public:
		virtual void onCreate();
		virtual bool onQuit();
		virtual void onDestroy();
		virtual void onResize();
		virtual void onTimer();
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_WINDOW_H_*/

