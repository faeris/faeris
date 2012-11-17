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

class Image2D;
class Texture2D:public FsObject
{
	public:
		static Texture* create(Image2D* img);
		static texture* LoadFromMgr(FsChar* name);
	private:
		FsUlong m_managed:1; /* managerd by texture manager */
		FsUlong m_mipmap:1;

		PixelFormat m_format;

		FsUint m_wrapS; 
		FsUint m_wrapT;

		FsUint m_magFilter;
		FsUint m_minFilter;

		FsUint m_width;		/* texture width*/
		FsUint m_height;	/* texture height*/

		FsPlatformTexture m_texName;
	public:
		FsUint getWidth()const{return m_width;} 
		FsUint getHeight()const{return m_height;}
		FsPlatformTexture getTexName(){return m_texture;}
	public:
		~Texture2D();
	protected:
		Texture2D(){}
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_TEXTURE_H_*/


