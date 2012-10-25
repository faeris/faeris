#include<stdio.h>
#include "FsLog.h"
#include "FsConfig.h"
#include "fsys/FsFile.h"
#include "fsys/FsVFS.h"
#include <stdarg.h>


FAERIS_NAMESPACE_BEGIN
FsLog* FsLog::ms_log=NULL;
FileLog* FileLog::ms_stdioFileLog=NULL;

void FsLog::init()
{
	if(ms_log==NULL)
	{
#if FS_CONFIG(FS_LOG_FILE)
		ms_log=FileLog::Create(FS_CONFIG(LOG_FILE_NAME));
#elif FS_CONFIG(FS_LOG_STDIO)
		ms_log=FileLog::getStdioFileLog();
#else
		ms_log=FileLog::getStdioFileLog();
#endif
	}
}

void FsLog::sLog(const FsChar* tag,const FsChar* fmt,...)
{
	init();
	va_list args;
	ms_log->log(tag,fmt,args);
	va_end(args);
}
void FsLog::sLog(const FsChar* fmt,...)
{
	init();
	va_list args;
	ms_log->log(fmt,args);
	va_end(args);
}

void FsLog::log(const FsChar* tag,const FsChar* fmt,...)
{
	FsChar buf[FS_MAX_LOG_BUF];
	FsUint fmtbyte=snprintf(buf,FS_MAX_LOG_BUF,"%s",tag);

	va_list args;
	va_start(args,fmt);
	snprintf(buf+fmtbyte,FS_MAX_LOG_BUF-fmtbyte,fmt,args);
	va_end(args);

	logMsg(buf);
}
void FsLog::log(const FsChar* fmt,...)
{
	FsChar buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	snprintf(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	logMsg(buf);
}


FileLog* FileLog::create(const FsChar* filename)
{

	FsFile* f=VFS::open(filename,VFS::FO_CREATE|VFS::FO_APPEND);
	if(f==NULL)
	{
		return NULL;
	}
	FileLog* fl=new FileLog(f);
	return fl;
}


FileLog* FileLog::getStdioFileLog()
{
	if(ms_stdioFileLog==NULL)
	{
		ms_stdioFileLog=new FileLog(VFS::getStdioFile());
	}
	return ms_stdioFileLog;
}


FileLog::FileLog(FsFile* file)
{
	m_file=file;
}

void FileLog::logMsg(const FsChar* msg)
{
	m_file->writeStr("%s\n",msg);
}

FileLog::~FileLog()
{
	delete m_file;
}

FAERIS_NAMESPACE_END
