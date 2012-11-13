#include "graphics/FsImage2D.h"
#include "fsys/FsFile.h"
#include "tinyjpeg/tinyjpeg.h"

FAERIS_NAMESPACE_BEGIN

Image2D* FsUtil_DecodeJpeg(FsFile* file)
{
	struct jdec_private* jdec=NULL;
	FsUchar* components[3];
	FsUchar*  buffer=NULL;

	FsUint width,height,length;
	Image2D* img=NULL;
	FsInt ret,read_bytes;

	file->seek(0,FsFile::FS_SEEK_END);
	length=file->tell();
	if(length==0)
	{
		FS_TRACE_ERROR("File Length Is Zero");
		return NULL;
	}
	file->seek(0,FsFile::FS_SEEK_SET);
	buffer=new FsUchar[length];

	read_bytes=file->read(buffer,length);
	if(read_bytes!=(FsInt)length)
	{
		FS_TRACE_ERROR("Read File Error,Except %d Bytes,But only %d Bytes Read",length,read_bytes);
		goto error;
	}	   
	jdec=tinyjpeg_init();
	if(jdec==NULL)
	{
		FS_TRACE_ERROR("Not Enough Memory To Alloc jdec_private struct");
		goto error;
	}
	ret=tinyjpeg_parse_header(jdec,buffer,length);
	if(ret<0)
	{
		FS_TRACE_ERROR("Parser Jpeg File Failed(%s)",tinyjpeg_get_errorstring(jdec));
		goto error;
	}
	tinyjpeg_get_size(jdec,&width,&height);

	ret=tinyjpeg_decode(jdec,TINYJPEG_FMT_RGB24);
	if(ret<0)
	{
		FS_TRACE_ERROR("Decode Jpeg File Failed(%s)",tinyjpeg_get_errorstring(jdec));
		goto error;
	}
	tinyjpeg_get_components(jdec,components);

	img=new Image2D(width,height,components[0],Image2D::FS_PIXEL_RGB888);
error:
	if(buffer)
	{
		delete[] buffer;
		buffer=NULL;
	}
	if(jdec)
	{
		tinyjpeg_free(jdec);
		jdec=NULL;
	}
	return img;

}

FAERIS_NAMESPACE_END
