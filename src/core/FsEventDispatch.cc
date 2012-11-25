#include "core/FsEventDispatch.h"
#include "core/FsEvent.h"
FAERIS_NAMESPACE_BEGIN

static EventDispatch* s_singleton=NULL;

EventDispatch* EventDispatch::instance()
{
	if(s_singleton==NULL)
	{
		s_singleton= new EventDispatch;
	}
	return s_singleton;
}

void EventDispatch::addListener(EventListener* l)
{
	m_listeners.push_back(l); 
}

void EventDispatch::removeListener(EventListener* l)
{
	Iterator iter;
	for(iter=m_listeners.begin();iter!=m_listeners.end();++iter)
	{
		if(*iter==l)
		{
			m_listeners.erase(iter);
			return;
		}
	}
	FS_TRACE_WARN("Can't Find EventListener");
}
void EventDispatch::dispatchEvent(Event* e)
{
	Iterator iter;
	FsInt type=e->getType();

	switch(type)
	{
		case FS_MOUSE_EVENT:
			for(iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->handleMouseEvent((MouseEvent*)e);
			}
			break;
		case FS_KEYBOARD_EVENT:
			for(iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->handleKeyboardEvent((KeyboardEvent*)e);
			}
			break;
		case FS_TOUCH_EVENT:
			for(iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->handleTouchEvent((TouchEvent*)e);
			}
			break;
		default:
			break;
	}
}



void EventListener::handleMouseEvent(MouseEvent* e){}
void EventListener::handleKeyboardEvent(KeyboardEvent *e){}
void EventListener::handleTouchEvent(TouchEvent* e){}
EventListener::~EventListener(){}


FAERIS_NAMESPACE_END

