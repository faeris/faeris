#include <GL/glut.h>

#define  checkImageWidth 64
#define  checkImageHeight 64

GLubyte checkImage[checkImageHeight][checkImageWidth][3];

void makeCheckImage(void)
{
	int i,j,c;
	for(i=0;i<checkImageHeight;i++)
	{
		for(j=0;j<checkImageWidth;j++)
		{
			c=(((i&0x8)==0)^((j&0x8)==0))*255;
			checkImage[i][j][0]=c;
			checkImage[i][j][1]=c;
			checkImage[i][j][2]=c;
		}
	}
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glPixelZoom(2.0,1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0,0);
	glDrawPixels(checkImageWidth,checkImageHeight,GL_RGB,GL_UNSIGNED_BYTE,checkImage);
	glFlush();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);

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

