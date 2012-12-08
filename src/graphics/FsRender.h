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
		void setModelViewMatrix(const Matrix44& m);
		void setProjectionMatrix(const Matrix44& m);
	public:
		void setViewport(FsInt x,FsInt y,FsInt width,FsInt height);
		void clear(FsBool color=true,FsBool depth=true,FsBool stencil=true);
	public:
		void setMaterial(Material* mat);
		void setFaceCulling(FsLong cull_face,FsLong front_face);
		void setScissor(FsInt x,FsInt y,FsInt width,FsInt height);
		void setClearColor(Color c);
		void setColor(const Color& c);
		void setLineWidth(FsFloat width);
		void setBlend(FsLong  equation,FsLong src,FsLong dst);
	public:
		void enableBlend(FsBool enable);

		void enableAlphaTest(FsBool enable);
		void enableDepthTest(FsBool enable);
		void enableScissorTest(FsBool enable);

		void enableDepthMask(FsBool enable);


	protected:
		void setLineMaterial(LineMaterial* mat);
		void setBaseMaterial(Material* mat);
		void setMeshMaterial(MeshMaterial* mat);
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

