#ifndef _FAERIS_SCENE_NODE_H_
#define _FAERIS_SCENE_NODE_H_

#include <string>

#include "FsMacros.h"
#include "FsObject.h"
#include "geometry/FsVector3.h"
#include "geometry/FsMatrix44.h"
#include "geometry/FsQuaternion.h"
#include "geometry/FsBoundSphere.h"
#include "geometry/FsBoundBox.h"
#include "util/FsListHead.h"

FAERIS_NAMESPACE_BEGIN


class SceneNode :public FsObject.h
{
	public:
		Node(std::string name);
		Node();
	public:
		virtual void update(FsLong msec);
		virtual void draw(Render* r);
	public:
		void applyMatrix(const Matrix44& m);

		Vector3 localToWorld(Vector3 l);
		Vector3 worldToLocal(Vector3 l);

		void lLookAt(Vector3 at);

		/* relation ship*/
		void addChirld(Node* n);
		void remove(node* n);
		void kill();

		Node* getChildByName(std::string name,FsBool recusive=0);

		void updateLocalMatrix();
		void updateWorldMatrix(FsBool force);

	public:
		virtual Node* clone(FsBool deep=0);
		virtual void draw(Render* );


	protected:
		void initData();


	protected:  

		/* flags */
		union 
		{
			struct{
				FsUlong m_matrixAutoUpdate:1;
				FsUlong m_matrixWorldNeedsUpdate:1;
				FsUlong m_useQuaternion:1;
				FsUlong m_hasSphere:1;
				FsUlong m_hasBox:1;
				FsUlong m_visible:1;
			};
			FsUlong m_flags;
		};


		std::string m_name;
		/* transform info */
		Vector3 m_position;
		Vector3 m_rotation;
		Vector3 m_eulerOrder;
		Vector3 m_scale;

		/* matrix */
		Matrix44 m_localMatrix;
		Matrix44 m_worldMatrix;

		/* use quaternion instead of euler rotation*/
		Quaternion m_quaternion;

		/* bool bounding  volume */
		BoundSphere m_boundSphere;
		BoundBox m_boundBox;


		/* relation ship*/
		Node* m_parent;
		ListHead<Node*> m_chirldHead;
		ListHead<Node*> m_slibing;

	private:
		FsLong m_existCnt;
};


FAERIS_NAMESPACE_END
#endif 

