#include <GL/glut.h>
static float spin=0;
static float angle=0.0;

int g_w;
int g_h;


void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	float lmodel_ambient[]={0.5,0.0,0.2,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);
}
void on_timer(int value)
{
	spin+=0.5;
	angle+=0.4;
	glutPostRedisplay();
	glutTimerFunc(20,on_timer,1);
}

void display(void)
{
	float position[]={0.0,0.0,1.5,1.0};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	/* first part */
	glViewport(0,0,g_w/2,g_h/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
	glRotated(angle,0.0,1.0,0.0);

	glPushMatrix();
	glRotated((double)spin,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glTranslated(0.0,0.0,1.5);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,0.0,1.0);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glutSolidTorus(0.275,0.85,80,150);


	/* second part */
	glViewport(0,g_h/2,g_w/2,g_h/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
	glRotated(angle+90,0.0,1.0,0.0);

	glPushMatrix();
	glRotated((double)spin,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glTranslated(0.0,0.0,1.5);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,0.0,1.0);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glutSolidTorus(0.275,0.85,80,150);

	/* third part */
	glViewport(g_w/2,0,g_w/2,g_h/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
	glRotated(angle+180,0.0,1.0,0.0);

	glPushMatrix();
	glRotated((double)spin,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glTranslated(0.0,0.0,1.5);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,0.0,1.0);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glutSolidTorus(0.275,0.85,80,150);

	/* four part */
	glViewport(g_w/2,g_h/2,g_w/2,g_h/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
	glRotated(angle+270,0.0,1.0,0.0);

	glPushMatrix();
	glRotated((double)spin,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glTranslated(0.0,0.0,1.5);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,0.0,1.0);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glutSolidTorus(0.275,0.85,80,150);


	glutSwapBuffers();
}
void reshape(int w,int h)
{
	g_w=w;
	g_h=h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(float)w/(float)h,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN) 
			{
				glutPostRedisplay();
			}
			break;
		default:
			break;
	}
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutTimerFunc(30,on_timer,1);
	glutMainLoop();
	return 0;
}



