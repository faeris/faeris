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


void Render::setMaterial(Material* mat)
{
	Material::MaterialType mat_type=mat->getMaterialType();
	switch(mat_type)
	{
		case FS_MATERIAL_BASE:
			setBaseMaterial(mat);
			break;
		case FS_MATERIAL_LINE:
			setLineMaterial((LineMaterial*)mat);
			break;
		case FS_MATERIAL_MESH:
			setMeshMaterial((MeshMaterial*)mat);
			break;
		default:
			FS_TRACE_WARN("Unkown Material Type(%d)",mat_type);
	}
}
void Render::setLineMaterial(LineMaterial* mat)
{
	setBaseMaterial(mat);
	setLineWidth(mat->lineWidth);
	enableFog(mat->fog);
	setColor(mat->color);
}
void Render::setBaseMaterial(Material* mat)
{
	setFrontSide(mat->frontSide);
	if(mat->transparent)
	{
		setGlobalAlpha(opacity);
	}

	if(mat->blending)
	{
		enableBlend(true);
		setBlend(mat->blendEquation,mat->blendSrc,mat->blendDst);
	}
	else
	{
		enableBlend(false);
	}

	enableDepthTest(mat->depthTest);
	setDepthMask(mat->depthMask);

	if(mat->polygonOffset)
	{
		enablePolygonOffset(true);
		setPolygonOffset(mat->polygonOffset,mat->polygonOffsetUnits);
	}
	else 
	{
		enablePolygonOffset(false);
	}
	enableAlphaTest(mat->alphaTest);
}












FAERIS_NAMESPACE_END
