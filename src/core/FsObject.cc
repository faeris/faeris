#include "FsObject.h"

FAERIS_NAMESPACE_BEGIN 

FsObject::~FsObject()
{
}
void FsObject::onDestory()
{
	delete this;
}
FAERIS_NAMESPACE_END 

