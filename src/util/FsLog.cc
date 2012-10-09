#include"util/FsLog.h"
#include<stdio.h>
#include"FsConfig.h"

FsLog* FsLog::ms_log=NULL;

void FsLog::sLog(const char* tag,const char* msg,...)
{
	if(ms_log==NULL)
	{
#if FS_CONFIG(LOG_FILE)
		ms_log=FsFileLog::Create(FS_CONFIG(LOG_FILE_NAME));
#elif FS_CONFIG(LOG_STDIO)
		ms_log=new FsStdioLog();
#else
	#warn "LOG_NOT_CONFIG"
#endif
	}
	if(ms_log==NULL)
	{
		return;
	}
	/*TODO*/
//	char buf[2048];

}

void FsStdioLog::log(const char* msg)
{
	printf("%s\n",msg);
}

FsFileLog* FsFileLog::create(const char* filename)
{

	FILE* f=fopen(filename);
	if(f==NULL)
	{
		return NULL;
	}
	FsFileLog* fl=FsFileLog((void*)f);
	return fl;
}

FsFileLog::create(void* data)
{
	m_data=data;
}

void FsFileLog::log(const char* msg)
{
	fsprintf((FILE*)m_data,"%s\n",msg);
}

FsFileLog::~FsFileLog()
{
	fclose((FILE*)m_data);
}

