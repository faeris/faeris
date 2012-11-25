#include "fsys/FsSys.h"

#include <unistd.h>
#include <errno.h>
#include <time.h>

FAERIS_NAMESPACE_BEGIN
FsLong Sys::getTime()
{
	return 0;

}
void Sys::usleep(FsLong time)
{
	struct timespec req= { time/1000, (time%1000)*1000000 };
	struct timespec rem;
	FsInt ret=0;
	while(1)
	{
		ret=nanosleep(&req,&rem);
		if(ret==-1)
		{
			if(errno==EINTR)
			{
				req=rem;
				nanosleep(&req,&rem);
				continue;
			}
		}
		break;
	}
}
FAERIS_NAMESPACE_END 
