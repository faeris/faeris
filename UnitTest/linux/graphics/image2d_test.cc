#include <stdio.h>
#include <stdlib.h>


#include "graphics/FsImage2D.h"
#include "util/FsImgDecoder.h"
#include "fsys/FsVFS.h"
#include "fsys/FsFile.h"

#include <GL/glut.h>

using namespace Faeris;
Image2D* img=NULL;
void init(int argc,char** argv)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_FLAT);
	glClearColor(0.0,0.0,0.0,0.0);
	img=new Image2D(255,255,Image2D::FS_PIXEL_RGB888);
	for(int i=0;i<255;i++)
	{
		for(int j=0;j<255;j++)
		{
			img->setColor(i,j,Color(i,(i+j)/2,j));
		}
	}

}

void display(void)
{
	if(img==NULL)
	{
		return;
	}
	glClear(GL_COLOR_BUFFER_BIT);

	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	
	GLint pixel_format=img->getPixelFormat()==Image2D::FS_PIXEL_RGB888?GL_RGB:GL_RGBA;
	glDrawPixels(img->getWidth(),img->getHeight(),pixel_format,GL_UNSIGNED_BYTE,img->getPixelData());
	glFlush();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	if(w<=h)
	{
		gluOrtho2D(0.0,1.0,0.0,1.0*h/w);
	}
	else
	{
		gluOrtho2D(0.0,1.0*w/h,0.0,1.0);
	}
}
static int leftFirst=GL_TRUE;

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 't':
		case 'T':
			leftFirst=!leftFirst;
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}

	if(leftFirst)
	{
		if(img)
		{
			delete img;
		}

		img=new Image2D(255,255,Image2D::FS_PIXEL_RGB888);
		FsUint width,height;
		width=img->getWidth();
		height=img->getHeight();
		FsUint i,j;

		for(i=0;i<width;i++)
		{
			for(j=0;j<height;j++)
			{

				img->setColor(i,j,Color(i,j,0));
			}
		}

		for(i=0;i<width;i++)
		{
			for(j=0;j<height;j++)
			{
				if(img->getColor(i,j)!=Color(i,j,0))
				{
					printf("Error Color\n");
				}
			}
		}
	}
	else 
	{
		if(img)
		{
			delete img;
		}
		img=new Image2D(255,255,Image2D::FS_PIXEL_RGBA8888);
		FsUint width,height;
		width=img->getWidth();
		height=img->getHeight();
		FsUint i,j;

		for(i=0;i<width;i++)
		{
			for(j=0;j<height;j++)
			{

				img->setColor(j,i,Color(i,j,0,128));
			}
		}
		for(i=0;i<width;i++)
		{
			for(j=0;j<height;j++)
			{
				if(img->getColor(i,j)!=Color(j,i,0,128))
				{
					printf("Error Color\n");
				}
			}
		}
	}
	glutPostRedisplay();
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init(argc,argv);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	if(img)
	{
		delete img;
	}
	return 0;
}





