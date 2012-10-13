#ifndef _FAERY_VFS_H_
#define _FAERY_VFS_H_
#include"util/FsSingleton.h"
#include"FsTypes.h"


FAERY_NAMESPACE_BEGIN

class FsIFile;

namespace FsVFS
{
	public:
		FsBool moduleInit();
		FsBool moduleExit();


		FsIFile* open(const FsChar* name);
		FsIFile* create(const FsChar* name);
		FsInt remove(const FsChar* name);
		FsInt copy(const FsChar* src,const FsChar* dst);
		FsBool exist(const FsChar* name);
		IDir* openDir(const FsChar* name);
		FsBool isDir(const FsChar* name);
		FsBool mapPackage(const FsChar* name);
};

FAERY_NAMESPACE_END

#endif 

