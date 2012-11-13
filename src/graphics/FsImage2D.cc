#include <string.h>
#include "graphics/FsImage2D.h"

FAERIS_NAMESPACE_BEGIN

FsUint Image2D::PixelFormatSize(PixelFormat f)
{
	FsUint pixel_bytes;
	switch(f)
	{
		case FS_PIXEL_UNKOWN:
			pixel_bytes=0;
			break;
		case FS_PIXEL_RGB888:
			pixel_bytes=3;
			break;
		case FS_PIXEL_RGBA8888:
			pixel_bytes=4;
			break;
		default:
			pixel_bytes=0;
			break;
	}
	FS_TRACE_WARN_ON(pixel_bytes==0,"UnKown PixelFormat");
	return pixel_bytes;
}
Image2D::Image2D(FsUint width,FsUint height,PixelFormat format)
{
	FsUint pixel_bytes=PixelFormatSize(format);
	if(pixel_bytes==0)
	{
		FS_TRACE_WARN("Unkown PixelFormat");
		m_width=0;
		m_height=0;
		m_format=FS_PIXEL_UNKOWN;
		m_pixel_bytes=0;
		m_buffer=0;
		return;
	}

	FsUint size=width*height*pixel_bytes;
	m_buffer=new FsUchar[size];
	memset(m_buffer,0,size);
	m_width=width;
	m_height=height;
	m_format=format;
	m_pixel_bytes=pixel_bytes;
} 

Image2D::Image2D(FsUint width,FsUint height,void* data,PixelFormat format)
{
	FsUint pixel_bytes=PixelFormatSize(format);
	if(pixel_bytes==0)
	{
		FS_TRACE_WARN("Unkown PixelFormat");
		m_width=0;
		m_height=0;
		m_format=FS_PIXEL_UNKOWN;
		m_pixel_bytes=0;
		m_buffer=0;
		return;
	}

	FsUint size=width*height*pixel_bytes;
	m_buffer=new FsUchar[size];
	memcpy(m_buffer,data,size);
	m_width=width;
	m_height=height;
	m_format=format;
	m_pixel_bytes=pixel_bytes;
}



Color Image2D::getColor(FsUint w,FsUint h)const 
{
	if(w>=m_width||h>=m_height)
	{
		FS_TRACE_WARN("Invalid Index");
		return Color::DEFAULT_COLOR;
	}
	Color ret;
	Color* p=(Color*)(m_buffer+(h*m_width+w)*m_pixel_bytes);
	switch(m_format)
	{
		case FS_PIXEL_RGB888:
			ret.r=p->r;
			ret.g=p->g;
			ret.b=p->b;
			ret.a=255;
			break;
		case FS_PIXEL_RGBA8888:
			ret=*p;
			break;
		default:
			FS_TRACE_WARN("UnKown Format Type");
	}
	return ret;
}

void Image2D::setColor(FsUint w,FsUint h,Color c)
{
	if(w>=m_width||h>m_height)
	{
		FS_TRACE_WARN("Invalid Index");
		return ;
	}
	Color* p=(Color*) (m_buffer+(h*m_width+w)*m_pixel_bytes);

	switch(m_format)
	{
		case FS_PIXEL_RGB888:
			p->r=c.r;
			p->g=c.g;
			p->b=c.b;
			break;
		case FS_PIXEL_RGBA8888:
			*p=c;
			break;
		default:
			FS_TRACE_WARN("UnKown Format Type");
	}
}
Image2D::~Image2D()
{
	if(m_buffer)
	{
		delete[] m_buffer;
		m_buffer=NULL;
	}
}
static const char* s_Image_Type="Image2D";
const char* Image2D::getName()
{
	return s_Image_Type;
}






FAERIS_NAMESPACE_END 

