#include "FsFile.h"
#include "stdarg.h"
FAERIS_NAMESPACE_BEGIN
FsLong FsFile::writeStr(const char* fmt,...)
{
	FsInt cnt=1024;

	while(1)
	{
		FsChar* buffer=new FsChar[cnt];

		va_list argptr;
		va_start(argptr,fmt);
		FsLong fmt_byte=vsnprintf(buffer,cnt,fmt,argptr);
		va_end(argptr);
		if(fmt_byte<cnt)
		{
			write(buffer,cnt);
			break;
		}
		cnt*=2;
		delete[] buffer;
	}





}
FAERIS_NAMESPACE_END
