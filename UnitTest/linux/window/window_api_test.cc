#include "core/FsWindow.h"
#include "core/FsFrame.h"
#include<stdio.h>
using namespace Faeris;
int main()
{
	Window* win=Window::create(0);
	if(win==NULL)
	{
		printf("create win error\n");
		return 0;
	}


	win->setSize(1024,800);
	win->setPosition(200,200);
	win->setName("Faeris.V1.0.1");
	win->show();
	win->hide();
	Frame::instance()->setFPS(60);
	Frame::instance()->start();
	
	return 0;

}
