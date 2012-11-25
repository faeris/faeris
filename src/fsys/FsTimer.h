#ifndef _FAERY_TIMER_H_
#define _FAERY_TIMER_H_ 
#include "FsMacros.h"
#include "FsConfig.h"

#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include <sys/time.h>
	typedef struct timeval PlatformTimeVal;
#else 
	#error "Unsupport Platform OS"
#endif 

FAERIS_NAMESPACE_BEGIN


class Timer
{
	public:
		Timer();
		void reset();
		FsLong now() const ;
	private:
		PlatformTimeVal m_begin;
};

FAERIS_NAMESPACE_END

#endif /*_FAERY_TIMER_H_*/

