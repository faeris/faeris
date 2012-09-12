#include"io/sys_file.h"
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

int SysFile::read(void* buf,size_t length)
{
	return fread(buf,length,1,mfile);
}

int SysFile::write(const void* buf,size_t length)
{
	return fwrite(buf,length,1,mfile);
}
long SysFile::seek(long offset,int where)
{
	off_t ret;
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
int SysFile::close()
{
	int ret=fclose(mfile);
	mfile=NULL;
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


