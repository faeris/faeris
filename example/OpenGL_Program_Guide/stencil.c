#include <GL/glut.h>

#define YELLOWMAT 1
#define BLUEMAT 2
void init(void)
{
	float yellow_diffuse[]={0.7,0.7,0.0,1.0};
	float yellow_specular[]={1.0,1.0,1.0,1.0};

	float blue_diffuse[]={0.1,0.1,0.7,1.0};
	float blue_specular[]={0.1,1.0,1.0,1.0};

	float position_one[]={1.0,1.0,1.0,0.0};

	glNewList(YELLOWMAT,GL_COMPILE);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,yellow_diffuse);
		glMaterialfv(GL_FRONT,GL_SPECULAR,yellow_specular);
		glMaterialf(GL_FRONT,GL_SHININESS,64.0);
	glEndList();

	glNewList(BLUEMAT,GL_COMPILE);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,blue_diffuse);
		glMaterialfv(GL_FRONT,GL_SPECULAR,blue_specular);
		glMaterialf(GL_FRONT,GL_SHININESS,45.0);
	glEndList();

	glLightfv(GL_LIGHT0,GL_POSITION,position_one);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	glClearStencil(0x0);
	glEnable(GL_STENCIL_TEST);

}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glStencilFunc(GL_EQUAL,0x1,0x1);
	glStencilOp(GL_KEEP,GL_KEEP,GL_KEEP);
	glCallList(BLUEMAT);
	glutSolidSphere(0.5,150,150);

	glPushMatrix();
		glRotatef(45.0,0.0,0.0,1.0);
		glRotatef(45.0,0.0,1.0,0.0);
		glCallList(YELLOWMAT);
		glutSolidTorus(0.275,0.85,150,150);

		glPushMatrix();
			glRotatef(90.0,1.0,0.0,0.0);
			glutSolidTorus(0.275,0.85,150,150);
		glPopMatrix();
	glPopMatrix();
	glFlush();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<h)
	{
		gluOrtho2D(-3.0,3.0,-3.0*(float)h/w,3.0*h/w);
	}
	else
	{
		gluOrtho2D(-3.0*w/h,3.0*w/h,-3.0,3.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_STENCIL_BUFFER_BIT);
	glStencilFunc(GL_ALWAYS,0x1,0x1);
	glStencilOp(GL_REPLACE,GL_REPLACE,GL_REPLACE);
	glBegin(GL_QUADS);
		glVertex2f(-1.0,0.0);
		glVertex2f(0.0,1.0);
		glVertex2f(1.0,0.0);
		glVertex2f(0.0,-1.0);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(float)w/h,3.0,7.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_STENCIL|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}



