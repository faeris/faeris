#ifndef _FAERY_IO_SYS_FILE_H_
#define _FAERY_IO_SYS_FILE_H_
#include"io/ifile.h"
#include<stdio.h>
class SysFile:public IFile 
{
	private:
		FILE* mfile;
		int m_cur_token;
		int m_cur_line;
		int m_scanner_line;
	public:
		static SysFile* open(const char* name,const char* mode);
	public:

		virtual int read(void* buf,size_t length);
		virtual int write(const void* buf,size_t length);
		virtual long seek(long offset,int where);
		virtual int close();
		virtual ~SysFile();
	private:
		SysFile(FILE* file){mfile=file;}
};
#endif 


