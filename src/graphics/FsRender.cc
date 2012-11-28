#include "graphics/FsRender.h"

FAERIS_NAMESPACE_BEGIN

static Render* s_singleton=NULL;
Render* Render::instance()
{
	if(s_singleton==NULL)
	{
		s_singleton=new Render();
	}
	return s_singleton;
}
void Render::setRenderTarget(const RenderTarget* t)
{
	if(m_renderTarget==t)
	{
		return ;
	}
	if(m_renderTarget!=NULL)
	{
		m_renderTarget->loseCurrent(this);
		m_renderTarget->Release();
	}
	if(t!=NULL)
	{
		m_renderTarget=t;
		m_renderTarget->addRef();
		m_renderTarget->makeCurrent(this);
	}
}





FAERIS_NAMESPACE_END
