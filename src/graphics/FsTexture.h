#ifndef _FAERIS_TEXTURE_H_
#define _FAERIS_TEXTURE_H_
#include "FsMacros.h"
#include "FsConfig.h"
#include "FsObject.h"

#if FS_CONFIG(FS_GL_RENDER)
	typedef FsUint FsPlatformTexture;
#else
	#error "Unsupport Texture Platfrom"
#endif 

FAERIS_NAMESPACE_BEGIN

class Image2d;
class Texture:public FsObject
{
	public:
		static Texture* create(Image2d* file_name);
	private:
		FsChar* m_fileName;
		FsUint m_width;
		FsUint m_height;
		FsPlatformTexture m_texture;
	public:
		FsUint getWidth()const{return m_width;} 
		FsUint getHeight()const{return m_height;}
		FsPlatformTexture getPlatformTexture(){return m_texture;}
	public:
		~Texture();
	protected:
		Texture(){}
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_TEXTURE_H_*/


