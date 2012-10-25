#include "FsVFS.h"
#include "FsSysFile.h"

FAERIS_NAMESPACE_BEGIN

FS_BEGIN_NAMESPACE(VFS)

FsFile* open(const FsChar* name,FsUint mode)
{
	return SysFile::open(name,mode);
}

FsFile* getStdoutFile()
{
	return SysFile::getStdoutFile();
}
FsFile* getStdinFile()
{
	return SysFile::getStdinFile();
}
FsFile* getStderrFile()
{
	return SysFile::getStderrFile();
}

FS_END_NAMESPACE(VFS)
FAERIS_NAMESPACE_END
