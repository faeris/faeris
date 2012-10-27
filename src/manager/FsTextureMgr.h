#ifndef _FAERIS_TEXTURE_MANAGER_H_
#define _FAERIS_TEXTURE_MANAGER_H_
#include "FsMacros.h"
#include "FsResourceManager.h"

#include "util/FsTSingeton.h"

FAERIS_NAMESPACE_BEGIN
class Texture;
class TextureMgr:public TSingeton<TextureMgr>,ResourceManager
{

}

FAERIS_NAMESPACE_END

#endif /*_FAERIS_TEXTURE_MANAGER_H_*/

