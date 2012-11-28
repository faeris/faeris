#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/glx.h>

#include "core/FsWindow.h"
#include "core/FsFrame.h"

typedef ::Window XWindow;

FAERIS_NAMESPACE_BEGIN

class WindowFrameListener;

static WindowFrameListener* s_listener=NULL;
static Display* s_dpy=NULL;
static std::vector<Window*> s_wins;

class PlatformWindow
{
	public:
		XWindow m_X11Window;
		Display* m_dpy;
		GLXContext m_contex;
};

static Display* s_X11GetDisplay()
{
	if(s_dpy==NULL)
	{
		s_dpy=XOpenDisplay(NULL);
		if(s_dpy==NULL)
		{
			FS_TRACE_WARN("Can't Connect to X  Server");
		}
	}
	return s_dpy;
}

class WindowFrameListener:public FrameListener
{
	public:
		virtual void frameBegin(FsLong now,FsLong diff)
		{
			Display* dpy=s_X11GetDisplay();
			XEvent event;
			FsLong event_mask=ExposureMask|KeyPressMask;
			while(XCheckMaskEvent(dpy,event_mask,&event))
			{
				std::vector<Window*>::iterator iter;
				for(iter=s_wins.begin();iter!=s_wins.end();++iter)
				{
					if(event.xany.window==(*iter)->getPlatformWindow()->m_X11Window)
					{
						(*iter)->handleEvent(&event);
					}
				}
			}
		}
};


static void s_RegisterWindow(Window* win)
{
	s_wins.push_back(win);
	if(s_wins.size()==1)
	{
		s_listener=new WindowFrameListener;
		Frame::instance()->addListener(s_listener);
	}
}

static void s_UnRegisterWindow(Window* win)
{
	std::vector<Window*>::iterator iter;
	for(iter=s_wins.begin();iter!=s_wins.end();++iter)
	{
		if((*iter)==win)
		{
			s_wins.erase(iter);
			if(s_wins.size()==0)
			{
				Frame::instance()->removeListener(s_listener);
				delete s_listener;
				s_listener=NULL;
				Frame::instance()->stop();
			}
		}
	}
	FS_TRACE_ERROR("Window Not Found,Some Bug Happend");
}



bool Window::init(FsLong flags)
{
	GLint attr[]={GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
	XWindow win,root;
	GLXContext glc;
	XSetWindowAttributes swa;

	Display* dpy=s_X11GetDisplay();
	if(dpy==NULL)
	{
		return 0;
	}
	root=DefaultRootWindow(dpy);
	XVisualInfo* vi=glXChooseVisual(dpy,0,attr);
	if(vi==NULL)
	{
		FS_TRACE_WARN("No Appropriate Visual Found");
		return 0;
	}
	Colormap cmap=XCreateColormap(dpy,root,vi->visual,AllocNone);
	swa.colormap=cmap;
	swa.event_mask=ExposureMask|KeyPressMask;
	win=XCreateWindow(dpy,root,0,0,600,600,0,vi->depth,InputOutput,vi->visual,
			CWColormap|CWEventMask,&swa);

	glc=glXCreateContext(dpy,vi,NULL,GL_TRUE);

	PlatformWindow* platwin=new PlatformWindow;

	platwin->m_X11Window=win;
	platwin->m_dpy=dpy;
	platwin->m_contex=glc;

	m_window=platwin;
	s_RegisterWindow(this);
	return true;
}

Window* Window::create(FsLong flags)
{
	Window* win=new Window(flags);
	if(!win->m_window)
	{
		delete win;
		return NULL;
	}
	return win;
}
Window::Window(FsLong flags)
{
	m_render=NULL;
	m_window=NULL;
	init(flags);
}
void Window::setName(const FsChar* name)
{
	XStoreName(m_window->m_dpy,m_window->m_X11Window,name);
}

void Window::setPosition(FsInt x,FsInt y)
{
	XMoveWindow(m_window->m_dpy,m_window->m_X11Window,x,y);
}

void Window::setSize(FsUint width,FsUint height)
{
	XResizeWindow(m_window->m_dpy,m_window->m_X11Window,width,height);
}

void Window::show()
{
	XMapWindow(m_window->m_dpy,m_window->m_X11Window);

}
void Window::hide()
{
	XUnmapWindow(m_window->m_dpy,m_window->m_X11Window);
}

FsInt Window::getWidth()
{
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	::Window w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return width;
}
FsInt Window::getHeight()
{
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	::Window w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return width;
}
FsInt Window::getPosX()
{
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return x;
}
FsInt Window::getPosY()
{
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	::Window w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return y;
}

void Window::handleEvent(void* e)
{
	FS_TRACE_WARN("Handle Event");
	FsUint width,height;
	XEvent* event=(XEvent*)e;
	switch(event->type)
	{
		case Expose:
			onDisplay();
			break;
		case ConfigureNotify:
			width=event->xconfigure.width;
			height=event->xconfigure.height;
			onResize(width,height);
			break;
		case ButtonPress:
			/*TODO*/
			break;
		case KeyPress:
			/*TODO*/
			break;
	}

}
void Window::onCreate(){}
void Window::onDisplay(){}
void Window::onFocuseIn(){}
void Window::onFocuseOut(){}
void Window::onMouseEnter(){}
void Window::onMouseLeave(){}
void Window::onKey(FsInt keycode,FsInt state,FsUlong mask){}
void Window::onMove(FsInt x,FsInt y,FsUlong mask){}
void Window::onMouse(FsInt button,FsInt state,FsInt x,FsInt y,FsUlong mask){}

bool Window::onQuit()
{
	return true;
}

void Window::onDestroy(){}
void Window::onResize(FsInt w,FsInt h){}

Window::~Window()
{
	if(m_render)
	{
		glXMakeCurrent(m_window->m_dpy,None,NULL);
	}
	if(m_window)
	{
		glXDestroyContext(m_window->m_dpy,m_window->m_contex);
		XDestroyWindow(m_window->m_dpy,m_window->m_X11Window);
		delete m_window;
		s_UnRegisterWindow(this);
	}
}

void Window::makeCurrent(Render* r)
{
	glXMakeCurrent(m_window->m_dpy,None,m_window->m_contex);
	m_render=r;
}
void Window::loseCurrent(Render* r)
{
	glXMakeCurrent(m_window->m_dpy,None,NULL);
	m_render=NULL;
}
void Window::swapBuffers()
{
	glXSwapBuffers(m_window->m_dpy,m_window->m_X11Window);
}
static const char* s_window_name="Window";
const char* Window::getName()
{
	return s_window_name;
}


FAERIS_NAMESPACE_END


















