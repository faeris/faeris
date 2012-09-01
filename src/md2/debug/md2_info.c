#include"md2.h"
#include<stdlib.h>

int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("usage %s <filename\n",argv[0]);
		exit(-1);
	}

	
	FILE* f=fopen(argv[1],"rb");
	if(f==NULL)
	{
		printf("Open File %s Failed\n",argv[1]);
		return -1;
	}

	struct SMD2Mesh* mesh=SMD2Mesh_Create(f);

	if(mesh==NULL)
	{
		printf("Bad Format\n");
		fclose(f);
		return -1;
	}

	SMD2Mesh_Print(mesh);
	SMD2Mesh_Destory(mesh);
	fclose(f);

	return 0;
}



