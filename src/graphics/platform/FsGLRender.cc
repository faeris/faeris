#include <GL/gl.h>
#include "graphics/FsRender.h"

void Render::Render()
{
	glClearColor(0,0,0,1);
	glClearDepth(1);
	glClearStencil(0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

void Render::pushMatrix()
{
	glPushMatrix();
}
void Render::popMatrix()
{
	glPopMatrix();
}
void Render::translate(const Vector3& v)
{
	glTransalefv(v.v);
}
void Render::scale(const Vector3& v)
{
	glScalefv(v.v);
}
void Render::setViewport(FsInt x,FsInt y,FsInt width,FsInt height)
{
	glViewport(x,y,width,height);
}

void Render::setClearColor(Color c)
{
	m_clearColor=c;
	glClearColor4ub(c.r,c.g,c.b,c.a);
}
Color Render::getClearColor()
{
	return m_clearColor;
}
void Render::clear(FsBool color,Fsbool depth,FsBool stencil)
{
	GLint flags=0;
	if(color) flags|=GL_COLOR_BUFFER_BIT;
	if(depth) flags|=GL_DEPTH_BUFFER_BIT;
	if(stencil) flags|=GL_STENCIL_BUFFER_BIT;
	glClear(flags);
}

void Render::setScissor(FsInt x,FsInt y,FsInt width,FsInt height)
{
	glScissor(x,y,width,height);
}
void Render::enableScissorTest(FsBool enable)
{
	if(m_scissorEnable!=enable)
	{
		if(enable)
		{
			glEnable(GL_SCISSOR_TEST);
		}
		else
		{
			glDisable(GL_SCISSOR_TEST);
		}
		m_scissorEnable=enable;
	}
}
void Render::enableDepthTest(FsBool enable)
{
	if(m_depthTest==enable)
	{
		if(enable)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
		m_depthTest=enable;
	}
}
void Render::setDepthMask(FsBool enable)
{
	if(m_depthMask!=enable)
	{
		glDepthMask(enable);
		m_depthMask=enable;
	}
}
void Render::setLineWidth(FsFloat width)
{
	if(m_lineWidth!=width)
	{
		glLineWidth(width);
		m_lineWidth=width;
	}
}

void Render::enablePolygonOffset(){}



