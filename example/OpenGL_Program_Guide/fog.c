#include<GL/glut.h>
#include<stdio.h>

static int fogMode;

static void init(void)
{
	float position[]={5,5,3.0,0.0};
	glEnable(GL_DEPTH_TEST);


	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glEnable(GL_LIGHTING);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHT0);
	{
		float mat_ambient[4]={0.1745,0.01175,0.01175,1.0};
		glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);

		float mat_diffuse[4]={0.61424,0.04236,0.04136,1.0};
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);

		float mat_specular[4]={0.727811,0.626959,0.626959,1.0};
		glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
		glMaterialf(GL_FRONT,GL_SHININESS,0.6*128.0);
	}

	glEnable(GL_FOG);
	{
		float fogColor[4]={0.5,0.5,0.5,1.0};
		fogMode=GL_EXP;

		glFogi(GL_FOG_MODE,fogMode);
		glFogfv(GL_FOG_COLOR,fogColor);
		glFogf(GL_FOG_DENSITY,0.35);
		glHint(GL_FOG_HINT,GL_DONT_CARE);
		glFogf(GL_FOG_START,1.0);
		glFogf(GL_FOG_END,5.0);
	}
	glClearColor(0.5,0.5,0.5,1.0);
}
static void renderShpere(float x,float y,float z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glutSolidSphere(0.4,100,100);
	glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	renderShpere(0,-0.5,-1.0);
	renderShpere(-1,-0.5,-2.0);
	renderShpere(1,-0.5,-2.0);
	renderShpere(-2,-0.5,-3.0);
	renderShpere(2,-0.5,-3.0);
	glutSwapBuffers();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*
	if(w<=h)
	{
		//glOrtho(-2.5,2.5,-2.5*h/w,2.5*h/w,-10.0,10.0);

	}
	else
	{
		glOrtho(-2.5*w/h,2.5*w/h,-2.5,2.5,-10.0,10.0);
	}
	*/
	gluPerspective(60,(float)w/h,1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-3);
}

static int ms_toggle=0;
static int ph_toggle=0;
static int lh_toggle=0;
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'f':
		case 'F':
			if(fogMode==GL_EXP)
			{
				fogMode=GL_EXP2;
				printf("Fog mode is GL_EXP2 \n");
			}
			else if(fogMode==GL_EXP2)
			{
				fogMode=GL_LINEAR;
				printf("Fog mode is GL_LINEAR\n");
			}
			else if(fogMode==GL_LINEAR)
			{
				fogMode=GL_EXP;
				printf("Fog mode is GL_EXP\n");
			}
			glFogi(GL_FOG_MODE,fogMode);
			glutPostRedisplay();
			break;
		case 'b':
		case 'B':
			ms_toggle=!ms_toggle;
			if(ms_toggle)
			{
				glEnable(GL_MULTISAMPLE);
			}
			else
			{
				glDisable(GL_MULTISAMPLE);
			}
			glutPostRedisplay();
			break;
		case 'p':
		case 'P':
			ph_toggle=!ph_toggle;
			if(ph_toggle)
			{
				glEnable(GL_POLYGON_SMOOTH);
			}
			else
			{
				glDisable(GL_POLYGON_SMOOTH);
			}
			glutPostRedisplay();
			break;
		case 'l':
		case 'L':
			lh_toggle=!lh_toggle;
			if(lh_toggle)
			{
				glEnable(GL_LINE_SMOOTH);
			}
			else
			{
				glDisable(GL_LINE_SMOOTH);
			}
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
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_MULTISAMPLE);
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
