#include <stdio.h>
#include "util/FsLog.h"

SysFile* SysFile::open(const char* name,FsUint mode)
{
	FILE* f=fopen(name,"w+");
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
