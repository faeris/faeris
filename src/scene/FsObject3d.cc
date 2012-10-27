#include "FsObject3D.h"

FAERIS_NAMESPACE_BEGIN
Object3D::Object3D()
	:m_ob(NULL)
{
}
Object3D::Object3D(Renderable* ob)
{
	ob->addRef();
	m_ob=ob;
}
void Object3D::attach(Renderable* ob)
{
	ob->addRef();
	if(m_ob)
	{
		m_ob->decRef();
	}
	m_ob=ob;
}
void Object3D::draw(Render* render)
{
	Node::drawBegin(render);
	if(m_ob)
	{
		m_ob->draw(render);
	}
	Node::drawEnd(render);
}
FAERIS_NAMESPACE_END
