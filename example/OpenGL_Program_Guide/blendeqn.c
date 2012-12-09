#include <GL/glut.h>

/* the following key change the selected blend aquation mode 
 *
 *  	'a' -> GL_FUNC_ADD
 *  	's' -> GL_FUNC_SUBTRACT
 *  	'r' -> GL_FUNC_REVERSE_SUBTRACT
 *  	'm'	-> GL_MIN
 *  	'x' -> GL_MAX
 *
 */

void init(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glBlendFunc(GL_ONE,GL_ONE);
	glEnable(GL_BLEND);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glRectf(-0.5,-0.5,0.5,0.5);
	glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'A':
		case 'a':
			glBlendEquation(GL_FUNC_ADD);

			break;
		case 's':case 'S':
			glBlendEquation(GL_FUNC_SUBTRACT);
			break;
		case 'r':case 'R':
			glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
			break;
		case 'm':case 'M':
			glBlendEquation(GL_MIN);
			break;
		case 'x':case 'X':
			glBlendEquation(GL_MAX);
			break;
		case 27:
			exit(0);
		default:
			break;
	}
	glutPostRedisplay();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(float)w/(float)h,1.0,30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-3.6);

}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}


			


