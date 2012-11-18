#include <stdio.h>

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
		case FsFile::FS_IO_RDONLY:
			f=fopen(name,"rb");
			break;
		case FsFile::FS_IO_WRONLY:
		case FsFile::FS_IO_RDWR:
			f=fopen(name,"r+b");
			break;
		case FsFile::FS_IO_APPEND:
			f=fopen(name,"ab");
			break;
		case FsFile::FS_IO_TRUNC:
			f=fopen(name,"wb");
			break;
		case FsFile::FS_IO_CREATE:
			f=fopen(name,"w+b");
			break;
		default:
			if(mode&FsFile::FS_IO_TRUNC)
			{
				f=fopen(name,"w+b");
			}
			else if(mode&FsFile::FS_IO_APPEND)
			{
				f=fopen(name,"ab");
			}
			else if(mode&FsFile::FS_IO_APPEND&FsFile::FS_IO_CREATE)
			{
				f=fopen(name,"a+b");
			}
			else
			{
				f=fopen(name,"r+b");
			}
			break;
	}
	
	if(f==NULL)
	{
		FS_TRACE_ERROR("Open File(%s) Failed",name);
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
		case FsFile::FS_SEEK_CUR:
			ret=fseek(m_platfromFile,offset,SEEK_CUR);
			break;
		case FsFile::FS_SEEK_SET:
			ret=fseek(m_platfromFile,offset,SEEK_SET);
			break;
		case FsFile::FS_SEEK_END:

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
