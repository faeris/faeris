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

	FsFile* file=NULL;

	unsigned int width,height;
	if(argc!=2)
	{
		printf("usage  %s <filename>\n",argv[0]);
		goto error;
	}
	file=VFS::open(argv[1]);
	if(file==NULL)
	{
		printf("open file %s failed\n",argv[1]);
		goto error;
	}

	img=FsUtil_PngReader(file);
	if(img==NULL)
	{
		printf("load png failed\n");
		goto error;
	}

	width=img->getWidth();
	height=img->getHeight();
	printf("ImageInfo: width=%d,height=%d,",width,height);
	if(img->getPixelFormat()==Image2D::FS_PIXEL_RGB888)
	{
		printf("format=RGB888\n");
	}
	else
	{
		printf("format=RGBA8888\n");
	}
	if(file)
	{
		delete file;
	}

	return ;
error:
	if(file!=NULL)
	{
		file->close();
		delete file;
		exit(-1);
	}
}

static int leftFirst=GL_TRUE;



void display(void)
{
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
	return 0;
}





