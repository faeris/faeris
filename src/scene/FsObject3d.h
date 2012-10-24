#ifndef _FAERIS_OBJECT3D_H_
#define _FAERIS_OBJECT3D_H_
#include "FsNode.h"

FAERIS_NAMESPACE_BEGIN
class Mesh;
class Object3D:public Node 
{
	public:
		Object3D();
		Object3D(Renderable* ob);
		void attach(Mesh* mesh)
		{
			Node::attach(mesh);
		}
	protected:
		void attach(Renderable* ob)
		{
			Node::attach(ob);
		}
	private:
		Renderable* m_ob;
};

FAERIS_NAMESPACE_END
#endif  /*_FAERIS_OBJECT3D_H_*/

