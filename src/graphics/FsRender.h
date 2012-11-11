#ifndef _FAERIS_RENDER_H_
#define _FAERIS_RENDER_H_
#include "FsMacros.h"
#include "math/FsMatrix44.h"
#include "FsConfig.h"

FAERIS_NAMESPACE_BEGIN
class Image2D;
class Render 
{
	public:
		static FsPlatformTexture genTexture2D(Image2D* img);
		/* for mipmap */
		static FsPlatformTexture genTexture2D(std::vector<Image2D*> imgs);
		static void delTexture2D(FsPlatformTexture  t);
	public:
		void save();
		void restore();
		void pushAttr(FsInt type);
		void popAttr(FsInt type);

		void matrixModel(FsInt type);
		void pushMatrix();
		void popMatrix();
		void mulMatrix(const Matrix44& m);
		void setMatrix(const Matrix44& m);
		void loadIdentity();

		/* if want to disable Texture,please let tex=NULL*/
		void bindTexture2D(Texture* tex);
		void textureCombineMode(FsUint type);
};

FAERIS_NAMESPACE_END

#endif /*_FAERIS_RENDER_H_*/

