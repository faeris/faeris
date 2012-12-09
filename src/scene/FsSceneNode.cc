#include "core/FsNode.h"

FAERIS_NAMESPACE_BEGIN
FsLong Node::m_existCnt=0;
Node::Node(std::string name)
{
	initData();
	m_name=name;
	m_existCnt++;
}

Node::Node()
{
	m_existCnt++;
	initData();
}

void Node::initData()
{
	m_matrixAutoUpdate=1;
	m_matrixWorldNeedsUpdate=1;
	m_useQuaternion=0;
	m_hasSphere=0;
	m_hasBox=0;
	m_visible=1;
	m_name=std::string("__unName__");
	m_parent=NULL;
}

void Node::applyMatrix(const Matrix44& m)
{
	m_localMatrix.mutilpy(m);

	m_scale=m_localMatrix.getScale();
	m_rotation=m_localMatrix.getEulerRotation(m_eulerOrder);
	m_postion=m_localMatrix.getTranslate();
}




FAERIS_NAMESPACE_END

