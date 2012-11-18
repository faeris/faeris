#include <stdio.h>
#include <stdlib.h>

#include "graphics/FsImage2D.h"
#include "util/FsImgDecoder.h"
#include "fsys/FsVFS.h"
#include "fsys/FsFile.h"

using namespace Faeris;
int main(int argc,char** argv)
{
	FsFile* file=NULL;
	Image2D* img=NULL;

	unsigned int width,height;
	if(argc!=2)
	{
		printf("usage  %s <filename>\n",argv[0]);
		goto error;
	}
	file=VFS::open(argv[1]);
	if(file==NULL)
	{
		printf("open file %s failed\n",argv[1]);
		goto error;
	}

	img=FsUtil_JpegReader(file);
	if(img==NULL)
	{
		printf("load jpeg failed\n");
		goto error;
	}

	width=img->getWidth();
	height=img->getHeight();

	printf("ImageInfo: width=%d,height=%d\n",width,height);

error:
	if(file!=NULL)
	{
		file->close();
		delete file;
	}
	if(img!=NULL)
	{
		delete img;
	}
	return 0;
}


