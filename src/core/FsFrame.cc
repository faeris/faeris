#include "core/FsFrame.h"
#include "fsys/FsSys.h"

FAERIS_NAMESPACE_BEGIN
static Frame* s_singleton=NULL;
Frame* Frame::instance()
{
	if(s_singleton==NULL)
	{
		s_singleton=new Frame;
	}
	return s_singleton;
}

Frame::Frame()
{
	m_stop=true;
	m_FPS=0;
	m_timer.reset();
	m_beginTime=m_timer.now();
	m_idleTime=0;
	m_curTime=m_timer.now();
	m_curFrame=0;
	m_frameTime=0;

	m_instantGap=1000;
	m_instantFrame=0;
	m_instantTime=0;
	m_instantFPS=0;
}


void Frame::setFPS(FsInt fps)
{
	m_FPS=fps;
	if(m_FPS==0)
	{
		m_frameTime=0;
	}
	else
	{
		m_frameTime=1000/m_FPS;
	}
}

FsInt Frame::getFPS()
{
	return m_FPS;
}

void Frame::start()
{
	FsLong lastframe_time,diff_time,frame_used;
	FsLong sleep_time;
	m_beginTime=m_timer.now();
	m_idleTime=0;
	m_curFrame=0;

	m_instantFPS=0;

	m_stop=false;
	m_curTime=m_timer.now();
	lastframe_time=m_curTime;

	m_instantTime=0;
	m_instantFrame=0;

	while(!m_stop)
	{

		diff_time=m_curTime-lastframe_time;

		frameBegin(m_curTime,diff_time);
		frameUpdate(m_curTime,diff_time);
		frameEnd(m_curTime,diff_time);

		frame_used=m_timer.now()-m_curTime;

		sleep_time=m_frameTime-frame_used;
		if(sleep_time>0)
		{
			m_idleTime+=sleep_time;
			Sys::usleep(sleep_time);
		}

		lastframe_time=m_curTime;
		m_curTime=m_timer.now();

		m_instantTime+=diff_time;
		m_curFrame++;
		m_instantFrame++;

		if(m_instantTime>m_instantGap)
		{
			m_instantFrame=0;
			m_instantFPS=m_instantFrame;
		}

	}
}
void Frame::frameBegin(FsLong now,FsLong diff)
{
	Iterator iter;
	for(iter=m_listener.begin();iter!=m_listener.end();++iter)
	{
		(*iter)->frameBegin(now,diff);
	}
}
void Frame::frameUpdate(FsLong now,FsLong diff)
{
	Iterator iter;
	for(iter=m_listener.begin();iter!=m_listener.end();++iter)
	{
		(*iter)->frameUpdate(now,diff);
	}
}
void Frame::frameEnd(FsLong now,FsLong diff)
{
	Iterator iter;
	for(iter=m_listener.begin();iter!=m_listener.end();++iter)
	{
		(*iter)->frameEnd(now,diff);
	}
}

void Frame::addFrameListener(FrameListener* l)
{
	m_listener.push_back(l);
}

void Frame::removeFrameListener(FrameListener* l)
{
	Iterator iter;
	for(iter=m_listener.begin();iter!=m_listener.end();++iter)
	{
		if(*iter==l)
		{
			m_listener.erase(iter);
			return;
		}
	}
	FS_TRACE_WARN("Can't Find Listener In Frame");
}


void Frame::stop()
{
	m_stop=true;
}
void Frame::setInstantGap(FsLong time)
{
	m_instantGap=time;
}
FsInt Frame::getInstantFPS()
{
	return m_instantFPS;
}
FsInt Frame::getAvgFPS()
{
	int seconds=(m_curTime-m_beginTime)/1000;
	if(seconds==0)
	{
		return 0;
	}
	else
	{
		return m_curFrame/seconds;
	}
}

void FrameListener::frameBegin(FsLong now,FsLong diff){}
void FrameListener::frameUpdate(FsLong now,FsLong diff){}
void FrameListener::frameEnd(FsLong now,FsLong diff){}
FrameListener::~FrameListener(){}


FAERIS_NAMESPACE_END

