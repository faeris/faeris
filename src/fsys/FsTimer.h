#ifndef _FAERY_TIMER_H_
#define _FAERY_TIMER_H_ 
#include"FsTypes.h"

FAERY_NAMESPACE_BEGIN

class FsTimer
{
	public:
		FsTimer();
		void reset();
		FsUlong now() const ;
	private:
		FsUlong m_beginTime;
};

FAERY_NAMESPACE_END

#endif /*_FAERY_TIMER_H_*/

