#include<stdio.h>
#include<GL/glut.h>
#include "FsMd2Loader.h"


using namespace Faeris;


int main(int argc,char** argv)
{
	Md2Model* g_model;
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
	printf("Md2File{\n");
	printf("\tFrameNu:%u\n",g_model->m_iFrameNu);
	printf("\tVertexNu:%u\n",g_model->m_iVertexNu);
	printf("\tTexCoordNu:%u\n",g_model->m_iTexCoordNu);
	printf("\tTriangleNu:%u\n",g_model->m_iTriangleNu);
	printf("\tTriagnles{\n");
	for(unsigned int j=0;j<g_model->m_iTriangleNu;j++)
	{
		printf("\t\t%u,%u,%u\n",g_model->m_pTriangles[j].m_iVertIndics[0],
								g_model->m_pTriangles[j].m_iVertIndics[1],
								g_model->m_pTriangles[j].m_iVertIndics[2]);
	}
	printf("\t}\n");

	for(unsigned int j=0;j<g_model->m_iFrameNu;j++)
	{
		Md2Frame* frame=g_model->m_pFrames+j;
		printf("\tFrame(%d,%s){\n",j,frame->m_caName);
		for(unsigned int i=0;i<g_model->m_iVertexNu;i++)
		{
			printf("\t\t%f,%f,%f\n",frame->m_pVerts[i].x,
					frame->m_pVerts[i].y,
					frame->m_pVerts[i].z
				  );
		}
		printf("\t}\n");
	}
	printf("}\n");

	return 0;
}



