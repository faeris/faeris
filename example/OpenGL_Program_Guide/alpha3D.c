#include<GL/glut.h>
#include<stdio.h>
#define MAXZ 8.0
#define MINZ -8.0
static float ZINC =0.1;

static float solidz=MAXZ;
static float transparentZ=MINZ;
static GLuint sphereList,cubeList;

static void init(void)
{
	float mat_specular[]= {1.0,1.0,1.0,0.15};
	float mat_shininess[]={100.0};
	float position[]={0.5,0.5,1.0,0.0};

	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	sphereList=glGenLists(1);
	glNewList(sphereList,GL_COMPILE);
		glutSolidSphere(0.4,100,100);
	glEndList();

	cubeList=glGenLists(1);
	glNewList(cubeList,GL_COMPILE);
		glutSolidCube(0.6);
	glEndList();
}

void display(void)
{
	float mat_solid[]={0.75,0.75,0.0,1.0};
	float mat_zero[]={0.0,0.0,0.0,1.0};
	float mat_transparent[]={0.0,0.8,0.8,0.6};
	float mat_emission[]={0.0,0.3,0.3,0.6};

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		glTranslatef(-0.15,-0.15,solidz);
		glMaterialfv(GL_FRONT,GL_EMISSION,mat_zero);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_solid);
		glCallList(sphereList);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0.15,0.15,transparentZ);
		glRotatef(15.0,1.0,1.0,0.0);
		glRotatef(30.0,0.0,1.0,0.0);

		glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_transparent);
		glEnable(GL_BLEND);
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE);
		glCallList(cubeList);
		glDepthMask(GL_TRUE);
		glDisable(GL_BLEND);
	glPopMatrix();
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
		glOrtho(-1.5,1.5,-1.5*h/w,1.5*h/w,-10.0,10.0);
	}
	else
	{
		glOrtho(-1.5*w/h,1.5*w/h,-1.5,1.5,10.0,10.0);
	}
	*/

	gluPerspective(40.0,(float)w/(float)h,1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-10);
}
void animate(value)
{
	printf("%f,%f\n",solidz,transparentZ);
	if(solidz<MINZ||transparentZ>=MAXZ)
	{
		ZINC=-ZINC;
	}
	if(solidz>MAXZ||transparentZ<MINZ)
	{
		ZINC=-ZINC;
	}
	solidz-=ZINC;
	transparentZ+=ZINC;
	glutTimerFunc(30,animate,1);
	glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'a':
		case 'A':
			solidz=MAXZ;
			transparentZ=MINZ;
			ZINC=0.1;
			break;
		case 'r':
		case 'R':
			solidz=MINZ;
			transparentZ=MAXZ;
			ZINC=0.1;
			break;
		case 27:
			exit(0);
	}
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutTimerFunc(30,animate,1);
	glutMainLoop();
	return 0;
}


















