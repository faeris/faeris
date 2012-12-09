#include<GL/glut.h>
#include<string.h>

#define checkImageWidth 64
#define checkImageHeight 64 

#define subImageWidth 16
#define subImageHeight 16 
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLubyte subImage[subImageHeight][subImageWidth][4];
static GLuint texName;

void makeCheckImage(void)
{
	int i,j,c;
	for(i=0;i<checkImageHeight;i++)
	{
		for(j=0;j<checkImageWidth;j++)
		{
			c=(((i&0x8)==0)^((j&0x8)==0))*255;
			checkImage[i][j][0]=255-c;
			checkImage[i][j][1]=255-c;
			checkImage[i][j][2]=c;
			checkImage[i][j][3]=255;
		}
	}
	memset(subImage,255,subImageHeight*subImageWidth*4);
	for(i=0;i<subImageHeight;i++)
	{
		for(j=0;j<subImageWidth;j++)
		{
			c=(((i&0x4)==0)^((j&0x4)==0))*255;
			subImage[i][j][0]=c;
			subImage[i][j][1]=255-c;
			subImage[i][j][2]=0;
			subImage[i][j][3]=255;
		}
	}
}
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 's':
		case 'S':
			glBindTexture(GL_TEXTURE_2D,texName);
			glTexSubImage2D(GL_TEXTURE_2D,0,12,44,
					subImageWidth,subImageHeight,GL_RGBA,
					GL_UNSIGNED_BYTE,subImage);
			glutPostRedisplay();
			break;
		case 'r':
		case 'R':
			glBindTexture(GL_TEXTURE_2D,texName);
			glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,
					checkImageWidth,checkImageHeight,0,
					GL_RGBA,GL_UNSIGNED_BYTE,checkImage);
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}


void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,checkImageWidth,checkImageHeight, \
			0,GL_RGBA,GL_UNSIGNED_BYTE,checkImage);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D,texName);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,0.0);glVertex3f(-2.0,-1.0,0.0);
	glTexCoord2f(0.0,1.0);glVertex3f(-2.0,1.0,0.0);
	glTexCoord2f(1.0,1.0);glVertex3f(0.0,1.0,0.0);
	glTexCoord2f(1.0,0.0);glVertex3f(0.0,-1.0,0.0);

	glTexCoord2f(0.0,0.0);glVertex3f(1.0,-1.0,0.0);
	glTexCoord2f(0.0,1.0);glVertex3f(1.0,1.0,0.0);
	glTexCoord2f(1.0,1.0);glVertex3f(2.41421,1.0,-1.41421);
	glTexCoord2f(1.0,0.0);glVertex3f(2.41421,-1.0,-1.41421);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);

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
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
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










