#include<stdio.h>
#include "FsLog.h"
#include "FsConfig.h"
#include "fsys/FsFile.h"
#include "fsys/FsVFS.h"
#include <stdarg.h>


FAERIS_NAMESPACE_BEGIN
FsLog* FsLog::ms_log=NULL;
FileLog* FileLog::ms_stdoutFileLog=NULL;

void FsLog::init()
{
	if(ms_log==NULL)
	{
#if FS_CONFIG(FS_LOG_FILE)
		ms_log=FileLog::Create(FS_CONFIG(LOG_FILE_NAME));
#elif FS_CONFIG(FS_LOG_STDIO)
		ms_log=FileLog::getStdoutFileLog();
#else
		ms_log=FileLog::getStdoutFileLog();
#endif
	}
}

static void FsLog_FormatLogBuffer(FsChar* buf,FsUlong size,
								   const FsChar* fmt,va_list ap)
{
	FsUint msg_len=vsnprintf(buf,size-1,fmt,ap);
	buf[msg_len]='\0';
}

static void FsLog_FormatLogTagBuffer(FsChar* buf,FsUlong size,
								const FsChar* tag,const FsChar* fmt,
								va_list ap)
{
	FsUint fmtbyte=snprintf(buf,size-1,"%s:",tag);
	FsUint msg_len=vsnprintf(buf+fmtbyte,size-1-fmtbyte,fmt,ap);
	buf[fmtbyte+msg_len]='\0';

}





void FsLog::sLog(const FsChar* tag,const FsChar* fmt,...)
{
	init();

	FsChar buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	ms_log->logMsg(buf);
}
void FsLog::sLog(const FsChar* fmt,...)
{
	init();
	FsChar buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	ms_log->logMsg(buf);
}

void FsLog::log(const FsChar* tag,const FsChar* fmt,...)
{
	FsChar buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	logMsg(buf);
}
void FsLog::log(const FsChar* fmt,...)
{
	FsChar buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
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


FileLog* FileLog::getStdoutFileLog()
{
	if(ms_stdoutFileLog==NULL)
	{
		ms_stdoutFileLog=new FileLog(VFS::getStdoutFile());
	}
	return ms_stdoutFileLog;
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
