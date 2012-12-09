#include "core/FsEvent.h"

FAERIS_NAMESPACE_BEGIN
FsInt MouseEvent::getType()
{
	return FS_MOUSE_EVENT;
}
FsInt KeyboardEvent::getType()
{
	return FS_KEYBOARD_EVENT;
}
FsInt TouchEvent::getType()
{
	return FS_TOUCH_EVENT;
}

FAERIS_NAMESPACE_END 

