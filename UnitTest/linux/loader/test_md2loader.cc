#include<stdio.h>
#include<GL/glut.h>
#include "FsMd2Loader.h"

static GLfloat spin=0.0;
static unsigned int g_frame_nu=0;

using namespace Faeris;

Md2Model* g_model;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin,1.0,1.0,1.0);
	glColor3f(1.0,1.0,1.0);
	//glRectf(-25.0,-25.0,25.0,25.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_TRIANGLES);
	{
		Md2Frame* frame=g_model->m_pFrames+g_frame_nu;
		Vector3* vs=frame->m_pVerts;
		for(unsigned int i=0;i<g_model->m_iTriangleNu;i++)
		{
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[0]].v);
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[1]].v);
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[2]].v);
		}
	}
	glEnd();

	/*
	glBegin(GL_LINES);
	{
		Md2Frame* frame=g_model->m_pFrames;
		Vector3* vs=frame->m_pVerts;
		for(unsigned int i=0;i<g_model->m_iTriangleNu;i++)
		{
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[0]].v);
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[1]].v);

			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[1]].v);
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[2]].v);

			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[2]].v);
			glVertex3fv(vs[g_model->m_pTriangles[i].m_iVertIndics[0]].v);
		}
	}
	glEnd();
	*/


	glPopMatrix();
	glutSwapBuffers();
}
void init()
{
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[]={50.0};
	GLfloat light_position[]={150,150,150,0.0};

	GLfloat light_ambient[]={0.0,0.0,0.8,1.0};
	GLfloat light_specular[]={0.5,0.5,0.5,1.0};
	GLfloat light_diffuse[]={.3,0.3,0.3,1.0};

	//GLfloat white_light[]={1.0,1.0,1.0,1.0};


	GLfloat lmodel_ambient[]={0.1,0.1,0.1,1.0};
	GLfloat spot_direction[]={100.00,100.0,100.0};

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
	//glDepth(1.0);
	//glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
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
	//gluPerspective(90,(float)w/(float)h,40,-1000);
	glOrtho(-100,100,-100,100,-100,100);
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
		case GLUT_RIGHT_BUTTON:
			g_frame_nu++;
			if(g_frame_nu>=g_model->m_iFrameNu)
			{
				g_frame_nu=0;
			}
		default:
			break;
	}
}
int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("useage %s <filename>\n",argv[0]);
		exit(0);
	}
	g_model=Md2Model::create(argv[1]);
	if(g_model==NULL)
	{
		printf("load model failed\n");
		exit(-1);
	}


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(900,700);
	glutCreateWindow("Test");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

