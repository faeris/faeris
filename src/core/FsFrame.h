#ifndef _FAERIS_FRAME_H_
#define _FAERIS_FRAME_H_

#include <vector>
#include "FsMacros.h"
#include "fsys/FsTimer.h"
FAERIS_NAMESPACE_BEGIN

class FrameListener
{
	public:
		virtual void frameBegin(FsLong now,FsLong diff);
		virtual void frameUpdate(FsLong now,FsLong diff);
		virtual void frameEnd(FsLong now,FsLong diff);
		virtual ~FrameListener();
};

class Frame 
{
	public:
		static Frame* instance();
	public:
		void setFPS(FsInt nu);
		FsInt getFPS();
		void start();
		void stop();

		void setInstantGap(FsLong time);
		FsInt getInstantFPS();

		FsInt getAvgFPS();

		void addFrameListener(FrameListener* l);
		void removeFrameListener(FrameListener* l);
	protected:
		void frameBegin(FsLong now,FsLong diff);
		void frameUpdate(FsLong now,FsLong diff);
		void frameEnd(FsLong now,FsLong diff);
	private:
		Frame();
	private:
		bool m_stop;
		FsInt m_FPS;

		Timer m_timer;

		FsLong m_beginTime;
		FsLong m_idleTime;
		FsLong m_curTime;
		FsLong m_curFrame;
		FsLong m_frameTime;

		FsLong m_instantGap;
		FsLong m_instantFrame;
		FsLong m_instantTime;
		FsLong m_instantFPS;

		typedef std::vector<FrameListener*>::iterator Iterator;
		std::vector<FrameListener*> m_listener;
};
FAERIS_NAMESPACE_END 

#endif /*_FAERIS_FRAME_H_*/

