#ifndef _FS_EVENT_LISTENER_H_
#define _FS_EVENT_LISTENER_H_
#include "FsMacros.h"
#include "core/FsEvent.h"
FAERIS_NAMESPACE_BEGIN
class EventListener
{
	public:
		virtual void handleMouseEvent(MouseEvent* e);
		virtual void handleKeyboardEvent(KeyboardEvent* e);
		virtual void handleTouchEvent(TouchEvent* e);
		virtual ~EventListener();
};
FAERIS_NAMESPACE_END

#endif /*_FS_EVENT_LISTENER_H_*/


