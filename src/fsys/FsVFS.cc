#include "FsVFS.h"
#include "FsSysFile.h"

FAERIS_NAMESPACE_BEGIN

FsFile* open(const FsChar* name,FsUint mode)
{
	return SysFile::open(name,mode);
}

FAERIS_NAMESPACE_END
