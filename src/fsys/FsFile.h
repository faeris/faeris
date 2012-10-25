#ifndef _FAERY_IO_IFILE_H_
#define _FAERY_IO_IFILE_H_

#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN

class FsFile
{
	public:
		enum
		{
			SK_SET,
			SK_CUR,
			SK_END,
		};
		enum
		{
			FO_RDONLY=0x1,
			FO_WRONLY=0x2,
			FO_RDWR=0x4,
			FO_APPEND=0x8,
			FO_CREATE=0x16,
			FO_TRUNC=0x32
		};
	public:
		virtual FsLong read(FsVoid* buf,FsLong length)=0;
		virtual FsLong write(const FsVoid* buf,FsLong length)=0;
		virtual FsLong seek(FsLong offset,FsInt where)=0;
		virtual FsInt  close()=0;
		virtual FsLong tell()=0;
		virtual ~FsFile(){}
	public:
		FsLong writeStr(const char* fmt,...);
};

FAERIS_NAMESPACE_END

#endif  /*_FAERY_IO_IFILE_H_*/

