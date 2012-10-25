#ifndef _FAERY_VFS_H_
#define _FAERY_VFS_H_

#include "FsFile.h" 
#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN
class FsDir;

FS_BEGIN_NAMESPACE(VFS)
enum
{
	FO_RDONLY=FsFile::FO_RDONLY,
	FO_WRONLY=FsFile::FO_WRONLY,
	FO_RDWR=FsFile::FO_RDWR,
	FO_APPEND=FsFile::FO_APPEND,
	FO_CREATE=FsFile::FO_CREATE,
	FO_TRUNC=FsFile::FO_TRUNC,
};
enum
{
	SK_SET=FsFile::SK_SET,
	SK_CUR=FsFile::SK_CUR,
	SK_END=FsFile::SK_END,
};

FsBool moduleInit();
FsBool moduleExit();

FsFile* open(const FsChar* name,FsUint mode=FO_RDONLY);
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

