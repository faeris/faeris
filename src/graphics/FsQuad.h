#ifndef _FAERIS_QUAD_H_
#define _FAERIS_QUAD_H_
#include "graphics/FsNode.h"
#include "FsMacros.h"
#include "graphics/FsRenderable.h"
#include "graphics/FsColor.h"

FAERIS_NAMESPACE_BEGIN
class Texture2D;
class Render;
class Quad:public FsNode
{
	public:
		Quad(const Color& color,FsUint width,FsUint height);
		Quad(const Texture2D* tex,FsUint width,FsUint,height);
		virtual ~Quad();
	public:
		FsFloat getWidth(){return m_width;}
		FsFloat getHeight(){return m_width;}
		void setWidth(FsFloat w){m_width=w;}
		void setHeight(FsFloat h){m_height=h;}
		void set(FsFloat w,FsFloat h){m_width=w;m_height=h;}
		void setColor(const Color& c){m_color=c;}
		void setTexture(Texture2D* tex);
		void setFillMode(FsInt type){m_fillType=type;}
		virtual void draw(Render* r);
	private:
		FsInt m_fillType;
		Color m_color;
		Texture2D* m_tex;
		FsFloat m_width;
		FsFloat m_height;
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_QUAD_H_*/

