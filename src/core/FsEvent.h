#ifndef _FAERIS_EVENT_H_
#define _FAERIS_EVENT_H_

#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN
class Event 
{
	public:
		virtual FsInt getType()=0;
};

class MouseEvent:public Event 
{
	public:
		virtual FsInt getType();
	public:
		FsInt button;
		FsInt state;
		FsInt x;
		FsInt y;

		/* used  for mouse move */
		FsInt dx;
		FsInt dy;
};

class KeyboardEvent:public Event 
{
	public:
		virtual FsInt getType();
	public:
		FsInt keycode;
		FsInt state;
};
class TouchEvent:public Event 
{
	public:
		virtual FsInt getType();
	public:
		/* TODO*/
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_EVENT_H_*/

