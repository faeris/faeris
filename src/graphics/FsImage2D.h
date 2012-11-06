#ifndef _FAERIS_IMAGE2D_H_
#define _FAERIS_IMAGE2D_H_
#include "FsMacros.h"
#include "util/FsShareBuffer.h"
#include "FsObject.h"
FAERIS_NAMESPACE_BEGIN
class FsFile;
class Image2D:public FsObject
{
	public:
		enum ImageType
		{
			IMG_UNKOWN=0;
			IMG_PNG=1;
			IMG_JPG=2;
			IMG_BMP=3;
		};
	public:
		static Image2D* loadFromFile(FsChar* name,FsUint type=IMG_UNKOWN);
		static Image2D* loadFromFile(FsFile* file,FsUint Type);

	public:
		Image2D(FsUint width,FsUint height,PixelFormat format);
		Image2D();
	public:
		FsUint getWidth()const{return m_width;} 
		FsUint getHeight()const{return m_height;};
		const FsChar* getBuffer();
		PixelFormat getPixelFormat()const;
		Pixel getPixel(FsUint x,FsUint y)const;
		void setPixel(FsUint x,FsUint y,const Pixel& pixel);
	private:
		FsUint m_width;
		FsUint m_height;
		PixelFormat m_format;
		ShareBuffer* m_buffer;
};
FAERIS_NAMESPACE_END
#endif /* _FAERIS_IMAGE2D_H_*/

