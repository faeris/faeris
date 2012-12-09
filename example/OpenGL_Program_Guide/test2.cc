#include<GL/glut.h>
static GLfloat spin=0.0;
static GLfloat tran=0.0;
static GLfloat diff=-0.01;
void init(void)
{
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[]={50.0};
	GLfloat light_position[]={1.5,1.5,1.5,0.0};

	GLfloat light_ambient[]={0.0,0.0,0.8,1.0};
	GLfloat light_specular[]={0.5,0.5,0.5,1.0};
	GLfloat light_diffuse[]={.3,0.3,0.3,1.0};

	GLfloat white_light[]={1.0,1.0,1.0,1.0};


	GLfloat lmodel_ambient[]={0.1,0.1,0.1,1.0};
	GLfloat spot_direction[]={-1.0,-1.0,-1.0};

	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);

	glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,500);
	glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spot_direction);
	glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,180);



	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);
}
void display(void)
{
	GLfloat light_position[]={0.0,0.0,1.5,0.0};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);

	{
		GLfloat mat_ambient[]={0.24725,0.1995,0.0745,1.0};
		GLfloat mat_diffuse[]={0.75164,0.60648,0.22648,1.0};
		GLfloat mat_specular[]={0.628281,0.555802,0.366065,1.0};
		glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
		glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
		glMaterialf(GL_FRONT,GL_SHININESS,51.2);
	}

	glPushMatrix();
		glRotated(spin,spin,spin,spin);
		glLightfv(GL_LIGHT0,GL_POSITION,light_position);
		glTranslatef(light_position[0],light_position[1],light_position[2]);
	//	glMaterialf(GL_FRONT,GL_EMISSION,50);
		glutSolidSphere(0.1,50,50);
	glPopMatrix();

	glTranslatef(tran,tran/2,tran/4);

	GLfloat mat_specular[]={0.393548,0.271906,0.166721,1.0};
	GLfloat mat_ambient[]={0.2125,0.1275,0.054,1.0};
	GLfloat mat_diffuse[]={0.714,0.4284,0.18144,1.0};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialf(GL_FRONT,GL_SHININESS,25.6);

	GLfloat light_ambient[]={0.2,0.2,0.2,1.0};
	GLfloat light_diffuse[]={0.8,0.8,0.8,1.0};
	GLfloat light_specular[]={0.8,0.8,0.8,1.0};

	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);

	glutSolidSphere(0.5,550,550);
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.5,1.5,-1.5, 1.5,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void spinDisplay(void)
{
	spin=spin+1.0;
	if(spin>360.0)
	{
		spin=spin-360;
	}
	if(tran>1.0)
	{
		diff=-0.01;
	}
	if(tran<-1.0)
	{
		diff=0.01;
	}

	tran+=diff;

	glutPostRedisplay();
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
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
