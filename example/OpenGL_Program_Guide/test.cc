#include<stdio.h>
#include<GL/glut.h>
static GLfloat spin=0.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glRectf(-25.0,-25.0,25.0,25.0);
	glPopMatrix();
	glutSwapBuffers();
}
void init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glShadeModel(GL_FLAT);
}
void spinDisplay(void)
{
	spin=spin+0.1;
	if(spin>360.0)
	{
		spin=spin-360;
	}
	glutPostRedisplay();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50,50,-50,50,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
		case GLUT_MIDDLE_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(250,250);
	glutCreateWindow("Test");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

