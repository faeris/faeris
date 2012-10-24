#ifndef _FAERY_SYS_FILE_H_
#define _FAERY_SYS_FILE_H_
#include "FsIFile.h"

FAERY_NAMESPACE_BEGIN

class FsSysFilePlateform;

class FsSysFile:public IFile 
{
	public:
		static SysFile* open(const FsChar* name,const FsChar* mode);
	public:
		virtual FsLong read(FsVoid* buf,FsLong length);
		virtual FsLong write(const FsVoid* buf,FsLong length);
		virtual FsLong seek(FsLong offset,FsInt where);
		virtual FsInt close();
		virtual FsLong tell();
		virtual ~SysFile();
	private:
		FsSysFilePlateform* m_platfromFile;
};
FAERY_NAMESPACE_END

#endif  /*_FAERY_SYS_FILE_H_*/


