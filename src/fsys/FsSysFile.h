#ifndef _FAERY_SYS_FILE_H_
#define _FAERY_SYS_FILE_H_

#include "FsMacros.h"
#include "FsFile.h"

FAERIS_NAMESPACE_BEGIN

#if FS_PLATFORM_OS(FS_OS_WIN) || FS_PLATFORM_OS(FS_OS_LINUX)
	#include<stdio.h>
	typedef FILE* SysFilePlateform ;
#else 
	#error "Error Platform For SysFile"
#endif 

class SysFile:public FsFile 
{
	public:
		static SysFile* open(const FsChar* name,FsUint mode);
		static SysFile* getStdoutFile();
		static SysFile* getStderrFile();
		static SysFile* getStdinFile();
	private:
		static SysFile* ms_stdout;
		static SysFile* ms_stdin;
		static SysFile* ms_stderr;
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


