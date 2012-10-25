#ifndef _FAERY_SYS_FILE_H_
#define _FAERY_SYS_FILE_H_

#include "FsMacros.h"
#include "FsFile.h"

FAERIS_NAMESPACE_BEGIN

#if defined(FS_OS_WIN) || defined(FS_OS_LINUX)
	#include<stdio.h>
	typedef FILE* SysFilePlateform ;
#else 
	#error "Error Platform For SysFile"
#endif 

class SysFile:public FsFile 
{
	public:
		static SysFile* open(const FsChar* name,FsUint mode);
	public:
		virtual FsLong read(FsVoid* buf,FsLong length);
		virtual FsLong write(const FsVoid* buf,FsLong length);
		virtual FsLong seek(FsLong offset,FsInt where);
		virtual FsInt close();
		virtual FsLong tell();
		virtual ~SysFile();
	protected:
		SysFile(SysFilePlateform f){m_platfromFile=f;}
	private:
		SysFilePlateform m_platfromFile;
};
FAERIS_NAMESPACE_END

#endif  /*_FAERY_SYS_FILE_H_*/


