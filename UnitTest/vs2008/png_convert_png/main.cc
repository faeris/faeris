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
	FsFile* outfile=NULL;
	Image2D* img=NULL;

	unsigned int width,height;
	int ret;
	if(argc!=3)
	{
		printf("usage  %s <filename> <outfile>\n",argv[0]);
		goto error;
	}
	file=VFS::open(argv[1]);
	if(file==NULL)
	{
		printf("open file %s failed\n",argv[1]);
		goto error;
	}

	img=FsUtil_PngReader(file);
	if(img==NULL)
	{
		printf("load jpeg failed\n");
		goto error;
	}

	width=img->getWidth();
	height=img->getHeight();

	printf("ImageInfo: Width=%d,Height=%d,",width,height);
	if(img->getPixelFormat()==Image2D::FS_PIXEL_RGB888)
	{
		printf("PixelFormat=FS_PIXEL_RGB_888\n");
	}
	else  if(img->getPixelFormat()==Image2D::FS_PIXEL_RGBA8888)
	{
		printf("PixelFormat=FS_PIXEL_RGBA_8888\n");
	}
	else 
	{
		printf("PixelFormat=Unkown\n");
	}

	outfile=VFS::open(argv[2],VFS::FS_IO_CREATE);
	if(outfile==NULL)
	{
		printf("Can't Create File %s\n",argv[2]);
		goto error;
	}

	ret=FsUtil_PngWriter(outfile,img);
	if(ret!=0)
	{
		printf("Save Image File failed\n");
		goto error;
	}


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
	if(outfile!=NULL)
	{
		outfile->close();
	}
	return 0;
}


