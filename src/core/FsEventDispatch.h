#ifndef _FAERIS_EVENT_DISPATCH_H_
#define _FAERIS_EVENT_DISPATCH_H_

#include <vector>
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

class EventDispatch
{
	public:
		static EventDispatch* instance();
	public:
		void addListener(EventListener* l);
		void removeListener(EventListener* l);
		void dispatchEvent(Event* e);

	private:
		typedef std::vector<EventListener*>::iterator Iterator;
		std::vector<EventListener*> m_listeners;
};
FAERIS_NAMESPACE_END

#endif  /*_FAERIS_EVENT_DISPATCH_H_*/

