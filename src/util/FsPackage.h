#ifndef _FAERIS_PACKAGE_H_
#define _FAERIS_PACKAGE_H_
#include "FsMacros.h"
#if FS_COMPRESS_METHOD(LZMA)
	#include "lzma.h"
#elif FS_COMPRESS_METHOD(UNZIP)
	#include "minizip.h"
#endif 

FAERIS_NAMESPACE_BEGIN
class FsFile;
class Package
{
	public:
		static Package* create(const Fschar* name);
	public:
		FsFile* getBlock(const FsChar* name);
	private:
		FsFile
};


	

FAERIS_NAMESPACE_END
#endif /*_FAERIS_PACKAGE_H_*/

