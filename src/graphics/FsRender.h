#ifndef _FAERIS_RENDER_H_
#define _FAERIS_RENDER_H_
#include "FsMacros.h"
#include "core/FsMatrix44.h"
#include "FsConfig.h"
#include "graphics/FsColor.h"
#include "core/FsVector3.h"

FAERIS_NAMESPACE_BEGIN

class Image2D;
class RenderTarget;

class Render 
{
	public:
		static Render* instance();
	public:
		void setRenderTarget(const RenderTarget* t);
		void swapBuffers();
	public:
		void pushMatrix();
		void popMatrix();
		void translate(const Vector3& v);
		void scale(const Vector3& v);
		void rotate(FsFloat angle,const Vector3& v);
		void setMatrix(const FsMatrix44& m);
	public:
		void setMeterial(const Material* m);
		void setViewport(FsInt x,FsInt y,FsInt width,FsInt height);

		void setScissor(FsInt x,FsInt y,FsInt width,FsInt height);

		void setClearColor(Color c);
		Color getClearColor()const{return m_clearColor;}

		void setFaceCulling(FsLong cull_face,front_face);

		void setLineWidth(FsFloat width);

		void clear(FsBool color=true,FsBool depth=true,FsBool stencil=true);
	private:
		Render();
	private:
		RenderTarget* m_renderTarget;
	private:
		FsLong m_doubleSided;
		FsLong m_FlipSided;

		/* clear */
		Color m_clearColor;



		/* Scissor*/
		FsLong m_enableScissor;

		/* depth */
		FsLong m_enableDepth;
		FsLong m_depthMask;

		/* alpha */
		FsLong m_enableBlend;
		FsLong m_blendEquation;
		FsLong m_blendSrc;
		FsLong m_blendDst;

		/* Polygon Offset */
		FsLong m_PolyonOffset;
		FsLong m_PolyonOffsetFactor;
		FsLong m_PolyonOffsetUnits;

		/* viewport */
		FsFloat m_viewportX;
		FsFloat m_viewportY;
		FsFloat m_viewportWidth;
		FsFloat m_viewportHeight;


		/* GPU capabilities */
		FsLong m_maxTextures;
		FsLong m_maxVectexTextures;
		FsLong m_maxTextureSize;

};

FAERIS_NAMESPACE_END

#endif /*_FAERIS_RENDER_H_*/

