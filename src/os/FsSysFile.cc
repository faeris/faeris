#include"io/FsSysFile.h"
#include<stdio.h>
#include"util/marocs.h"

SysFile* SysFile::open(const char* name,const char* mode)
{
	FILE* f=fopen(name,mode);
	if(f==NULL)
	{
		DEBUG("Open File(%s) Failed",name);
		return NULL;
	}
	return new SysFile(f);
}

FsLong SysFile::read(void* buf,FsLong length)
{
	return fread(buf,1,length,mfile);
}

FsLong SysFile::write(const void* buf,FsLong length)
{
	return fwrite(buf,1,length,mfile);
}
FsLong SysFile::seek(FsLong offset,FsInt where)
{
	FsLong ret;
	switch(where)
	{
		case IFile::IF_CUR:
			ret=fseek(mfile,offset,SEEK_CUR);
			break;
		case IFile::IF_SET:
			ret=fseek(mfile,offset,SEEK_SET);
			break;
		case IFile::IF_END:
			ret=fseek(mfile,offset,SEEK_END);
			break;
		default:
			ret=-1;
	}
	return ret;
}
FsInt SysFile::close()
{
	FsInt ret=0;
	if(mfile)
	{
		ret=fclose(mfile);
		mfile=NULL;
	}
	return ret;
}
SysFile::~SysFile()
{
	if(mfile!=NULL)
	{
		fclose(mfile);
		mfile=NULL;
	}
}


