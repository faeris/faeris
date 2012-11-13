#ifndef _FAERY_VFS_H_
#define _FAERY_VFS_H_

#include "FsFile.h" 
#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN
class FsDir;

FS_BEGIN_NAMESPACE(VFS)
enum
{
	FS_IO_RDONLY=FsFile::FS_IO_RDONLY,
	FS_IO_WRONLY=FsFile::FS_IO_WRONLY,
	FS_IO_RDWR=FsFile::FS_IO_RDWR,
	FS_IO_APPEND=FsFile::FS_IO_APPEND,
	FS_IO_CREATE=FsFile::FS_IO_CREATE,
	FS_IO_TRUNC=FsFile::FS_IO_TRUNC,
};
enum
{
	FS_SEEK_SET=FsFile::FS_SEEK_SET,
	FS_SEEK_CUR=FsFile::FS_SEEK_CUR,
	FS_SEEK_END=FsFile::FS_SEEK_END,
};

FsBool moduleInit();
FsBool moduleExit();

FsFile* open(const FsChar* name,FsUint mode=FS_IO_RDONLY);
FsFile* create(const FsChar* name);
FsInt remove(const FsChar* name);
FsInt copy(const FsChar* src,const FsChar* dst);
FsBool exist(const FsChar* name);
FsDir* openDir(const FsChar* name);
FsBool isDir(const FsChar* name);
FsBool mapPackage(const FsChar* name);

FsFile* getStdoutFile(); 
FsFile* getStdinFile(); 
FsFile* getStderrFile(); 

FS_END_NAMESPACE(VFS)
FAERIS_NAMESPACE_END

#endif 

