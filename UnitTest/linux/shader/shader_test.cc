#include <stdio.h>
#include <stdlib.h>
#include "fsys/FsVFS.h"
#include "fsys/FsFile.h"
#include "graphics/FsShader.h"
#include "graphics/FsProgram.h"

#include <GL/glew.h>
#include <GL/glut.h>
using namespace Faeris;

Shader* vertex=NULL;
Shader* fragment=NULL;
Program* program=NULL;

GLint loc;
void init(int argc,char** argv)
{
	glEnable(GL_DEPTH);
	glShadeModel(GL_SMOOTH);
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error %s\n", glewGetErrorString(err));
		exit(1);
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	if(argc<2||argc>3)
	{
		printf("usage %s <vertexshader> <fragmentshader>\n",argv[0]);
		exit(-1);
	}

	if(argc==2)
	{
		FsFile* file=VFS::open(argv[1]);
		if(file==NULL)
		{
			printf("Open Vertex File Failed\n");
			exit(-1);
		}
		vertex=Shader::create(file,Shader::FS_VERTEX_SHADER);
		delete file;
		if(vertex==NULL)
		{
			printf("Create Vertex Shader Failed\n");
			exit(-1);
		}
	}
	else if(argc==3)
	{
		FsFile* vertex_file=VFS::open(argv[1]);
		FsFile* fragment_file=VFS::open(argv[2]);
		if(vertex_file==NULL)
		{
			printf("Open Vertex Shader File Failed\n");
			exit(-1);
		}
		if(fragment_file==NULL)
		{
			printf("Open Fragment Shader File Failed\n");
			delete vertex_file;
			exit(-1);
		}
		vertex=Shader::create(vertex_file,Shader::FS_VERTEX_SHADER);
		if(vertex==NULL)
		{
			printf("Create Vertex Shader Failed\n");
			delete vertex_file;
			delete fragment_file;
			exit(-1);
		}
		fragment=Shader::create(fragment_file,Shader::FS_FRAGMENT_SHADER);
		if(fragment==NULL)
		{
			printf("Create Fragment Shader Failed\n");
			delete vertex_file;
			delete fragment_file;
			vertex->release();
			exit(-1);
		}
		delete vertex_file;
		delete fragment_file;
	}
	program=Program::create(vertex,fragment);
	if(program==NULL)
	{
		printf("Create program Failed\n");
		if(vertex)
		{
			vertex->release();
		}
		if(fragment)
		{
			fragment->release();
		}
		exit(-1);
	}
	glUseProgram(program->getPlatformProgram());
	loc=glGetUniformLocation(program->getPlatformProgram(),"lightDir");
}

float time=1;
void display(void)
{
	glUniform3f(loc,200,100,time);
	glClearColor(0.0,0.0,0.0,1.0);
	glColor4f(1.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,
			0.0,0.0,0.0,
			0.0f,1.0f,0.0f);
	glMatrixMode(GL_MODELVIEW);
	glutSolidTeapot(1);
	glutSwapBuffers();
}

void onTimer(int value)
{
	time+=1;
	if(time>2000)
	{
		time=1;
	}
	glutTimerFunc(30,onTimer,1);
	glutPostRedisplay();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(70,(float)w/(float)h,1,1000);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int mouse,int state,int x,int y)
{
	if(mouse==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			time+=0.01;
			glutPostRedisplay();
		}
	}
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init(argc,argv);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutTimerFunc(30,onTimer,1);
	glutMainLoop();
	if(vertex)
	{
		vertex->release();
	}
	if(fragment)
	{
		fragment->release();
	}
	if(program)
	{
		program->release();
	}
	printf("over\n");

	return 0;
}




