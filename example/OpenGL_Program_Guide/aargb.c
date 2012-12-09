#include<GL/glut.h>
#include<stdio.h>

static float rotAngle=0;

void init(void)
{
	float values[2];
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY,values);
	printf("GL_LINE_WIDTH_GRANULARITY value is %3.1f \n",values[0]);

	glGetFloatv(GL_LINE_WIDTH_RANGE,values);
	printf("GL_LINE_WIDTH_RANGE value are %3.1f to %3.1f \n",
			values[0],values[1]);
//	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT,GL_DONT_CARE);
	glLineWidth(2.5);

	glClearColor(0.0,0.0,0.0,0.0);

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	glPushMatrix();
	glRotatef(-rotAngle,0.0,0.0,0.1);
	glBegin(GL_LINES);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	glPopMatrix();

	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
	glRotatef(rotAngle,0.0,0.0,1.0);
	glBegin(GL_LINES);
		glVertex2f(0.5,0.5);
		glVertex2f(-0.5,-0.5);
	glEnd();
	glPopMatrix();
	glFlush();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	{
		gluOrtho2D(-1.0,1.0,
				-1.0*(float)h/w,1.0*(float)h/w);

	}
	else 
	{
		gluOrtho2D(-1.0*w/h,1.0*w/h,-1.0,1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int hit_toggle=0;
int smooth_toggle=0;
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'r':
		case 'R':
			rotAngle+=5;
			if(rotAngle>=360) rotAngle=0;
			glutPostRedisplay();
			break;
		case 'h':
		case 'H':
			hit_toggle=!hit_toggle;
			if(hit_toggle)
			{
				glEnable(GL_LINE_SMOOTH);
			}
			else
			{
				glDisable(GL_LINE_SMOOTH);
			}
			glutPostRedisplay();
			break;
		case 's':
		case 'S':
			smooth_toggle=!smooth_toggle;
			if(smooth_toggle)
			{
				glHint(GL_LINE_SMOOTH,GL_NICEST);
			}
			else
			{
				glHint(GL_LINE_SMOOTH,GL_FASTEST);
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
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


