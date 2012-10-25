#include "FsFile.h"
#include "stdarg.h"
#include "stdio.h"
FAERIS_NAMESPACE_BEGIN
FsLong FsFile::writeStr(const char* fmt,...)
{
	FsInt cnt=1024;
	FsLong fmt_byte=0;

	while(1)
	{
		FsChar* buffer=new FsChar[cnt];

		va_list argptr;
		va_start(argptr,fmt);
		fmt_byte=vsnprintf(buffer,cnt,fmt,argptr);
		va_end(argptr);
		if(fmt_byte<cnt)
		{
			buffer[fmt_byte]='\0';
			write(buffer,fmt_byte+1);
			delete[] buffer;
			break;
		}
		cnt*=2;
		delete[] buffer;
	}
	return  fmt_byte;





}
FAERIS_NAMESPACE_END
