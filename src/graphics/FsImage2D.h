#ifndef _FAERIS_IMAGE2D_H_
#define _FAERIS_IMAGE2D_H_
#include "FsMacros.h"
#include "core/FsObject.h"
#include "graphics/FsColor.h"
FAERIS_NAMESPACE_BEGIN
class Image2D:public FsObject
{
	public:
		enum PixelFormat
		{
			FS_PIXEL_UNKOWN=0,
			FS_PIXEL_RGB888,
			FS_PIXEL_RGBA8888,
		};

		enum ImageType
		{
			FS_IMAGE_UNKWON=0,
			FS_IMAGE_PNG,
			FS_IMAGE_JEPG,
			FS_IMAGE_TGA,
			FS_IMAGE_BMP,
		};
		static FsUint PixelFormatSize(PixelFormat f);

	public:
		Image2D(FsUint width,FsUint height,PixelFormat format);
		Image2D(FsUint width,FsUint height,void* data,PixelFormat format);
	public:
		virtual ~Image2D();
		virtual const char* getName();
	public:
		FsUint getWidth()const{return m_width;} 
		FsUint getHeight()const{return m_height;};
		const FsUchar* getPixelData()const{return m_buffer;}
		PixelFormat getPixelFormat()const{return m_format;}
		Color getColor(FsUint x,FsUint y)const;
		void setColor(FsUint x,FsUint y,Color c);
	private:
		FsUint m_pixel_bytes;
		FsUint m_width;
		FsUint m_height;
		PixelFormat m_format;
		FsUchar* m_buffer;
};
FAERIS_NAMESPACE_END
#endif /* _FAERIS_IMAGE2D_H_*/

