#include<GL/glut.h>
unsigned char rasters[24]=
{ 
	0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xc0,0x00,0xc0,0x00,0xff,0x00,
	0xff,0x00,0xc0,0x00,0xc0,0x00,
	0xc0,0x00, 0xff,0xc0,0xff,0xc0
};

void init(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glClearColor(0.0,0.0,0.0,0.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2i(20,20);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glFlush();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,w,0.0,h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}




