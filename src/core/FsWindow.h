#ifndef _FAERIS_WINDOW_H_
#define _FAERIS_WINDOW_H_ 
#include <vector>

#include "FsMacros.h"
#include "graphics/FsRenderTarget.h"
#include "FsConfig.h"
#include "core/FsEvent.h"
#include "core/FsEventListener.h"

FAERIS_NAMESPACE_BEGIN

class PlatformWindow;
class Window:public RenderTarget
{
	public:
		static Window* create(FsLong flags);
		
	public:
		virtual void makeCurrent(Render* r);
		virtual void loseCurrent(Render* r);
		virtual void swapBuffers();
	public:
		void setName(const FsChar* name);
		void setPosition(FsInt x,FsInt y);
		void setSize(FsUint width,FsUint height);
		void show();
		void hide();
		void setStyle(FsLong flags);

		FsInt getWidth();
		FsInt getHeight();
		FsInt getPosX();
		FsInt getPosY();

	public:
		void addEventListener(EventListener* l);
		void removeEventListener(EventListener* l);
		void dropAllEventListener(EventListener* l);
	public:
		virtual void onCreate();

		virtual void onDisplay();

		virtual void onFocuseIn();
		virtual void onFocuseOut();

		virtual void onMouseEnter();
		virtual void onMouseLeave();

		virtual void onKey(FsInt keycode,FsInt state,FsUlong mask);
		virtual void onMouse(FsInt button,FsInt state,FsInt x,FsInt y,FsUlong mask);
		virtual void onMove(FsInt x,FsInt y,FsUlong mask);

		virtual bool onQuit();
		virtual void onDestroy();

		virtual void onResize(FsInt w,FsInt h);
		virtual const char* getName();
		virtual ~Window();

	public:
		void handleEvent(void* e);

	protected:
		Window(FsLong flags);
		bool init(FsLong flags);
	public:
		PlatformWindow* getPlatformWindow(){return m_window;}

	private:
		
		Render* m_render;

		/* EventListener*/
		typedef std::vector<EventListener*>::iterator Iterator;
		std::vector<EventListener*> m_listeners;

		/* PlatformWindow */
		PlatformWindow* m_window;
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_WINDOW_H_*/

