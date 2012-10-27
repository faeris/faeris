#include <stdio.h>
#include "util/FsLog.h"

FAERIS_NAMESPACE_BEGIN

SysFile* SysFile::ms_stdout=NULL;
SysFile* SysFile::ms_stdin=NULL;
SysFile* SysFile::ms_stderr=NULL;

SysFile* SysFile::getStdoutFile()
{
	if(ms_stdout==NULL)
	{
		ms_stdout=new SysFile(stdout);
	}
	return ms_stdout;
}
SysFile* SysFile::getStdinFile()
{
	if(ms_stdin==NULL)
	{
		ms_stdin=new SysFile(stdout);
	}
	return ms_stdin;
}
SysFile* SysFile::getStderrFile()
{
	if(ms_stderr==NULL)
	{
		ms_stderr=new SysFile(stdout);
	}
	return ms_stderr;
}


SysFile* SysFile::open(const char* name,FsUint mode)
{
	FILE* f=NULL;
	switch(mode)
	{
		case FsFile::FO_RDONLY:
			f=fopen(name,"r");
			break;
		case FsFile::FO_WRONLY:
		case FsFile::FO_RDWR:
			f=fopen(name,"r+");
			break;
		case FsFile::FO_APPEND:
			f=fopen(name,"a");
			break;
		case FsFile::FO_TRUNC:
			f=fopen(name,"w");
			break;
		case FsFile::FO_CREATE:
			f=fopen(name,"w+");
			break;
		default:
			if(mode&FsFile::FO_TRUNC)
			{
				f=fopen(name,"w+");
			}
			else if(mode&FsFile::FO_APPEND)
			{
				f=fopen(name,"a");
			}
			else if(mode&FsFile::FO_APPEND&FsFile::FO_CREATE)
			{
				f=fopen(name,"a+");
			}
			else
			{
				f=fopen(name,"r+");
			}
			break;
	}
	
	if(f==NULL)
	{
		FS_LOG_DEBUG("Open File(%s) Failed",name);
		return NULL;
	}
	return new SysFile(f);
}

FsLong SysFile::read(void* buf,FsLong length)
{
	return fread(buf,1,length,m_platfromFile);
}

FsLong SysFile::write(const void* buf,FsLong length)
{
	return fwrite(buf,1,length,m_platfromFile);
}
FsLong SysFile::seek(FsLong offset,FsInt where)
{
	FsLong ret;
	switch(where)
	{
		case FsFile::SK_CUR:
			ret=fseek(m_platfromFile,offset,SEEK_CUR);
			break;
		case FsFile::SK_SET:
			ret=fseek(m_platfromFile,offset,SEEK_SET);
			break;
		case FsFile::SK_END:

			ret=fseek(m_platfromFile,offset,SEEK_END);
			break;
		default:
			ret=-1;
	}
	return ret;
}
FsLong SysFile::tell()
{
	return ftell(m_platfromFile);
}
FsInt SysFile::close()
{
	FsInt ret=0;
	if(m_platfromFile)
	{
		ret=fclose(m_platfromFile);
		m_platfromFile=NULL;
	}
	return ret;
}
SysFile::~SysFile()
{
	if(m_platfromFile!=NULL)
	{
		fclose(m_platfromFile);
		m_platfromFile=NULL;
	}
}

FAERIS_NAMESPACE_END
