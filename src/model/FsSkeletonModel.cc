#include "model/FsSkeletonModel.h"

FAERIS_NAMESPACE_BEGIN

SkeletonModel* SkeletonModel::create(const FsChar* filename)
{
	SkeletonMesh* mesh;
	mesh=loadFromMgr(filename);
	if(mesh==NULL)
	{
		FS_TRACE_WARN("Create SkeletonModel Failed");
		return NULL;
	}
	SkeletonModel* model=new SkeletonModel(mesh);
	mesh->release();
	return model;
}

SkeletonModel::SkeletonModel(SkeletonMesh* mesh)
{
	mesh->addRef();
	m_mesh=mesh;
	m_curAnimation=NULL;
	m_curFrame=0;
	m_curFrameTime=0;
	m_perFrameTime=0;
	m_loop=false;
}

SkeletonModel::~SkeletonModel()
{
	m_mesh->release();
}

void SkeletonModel::update(FsLong msec)
{
	if(m_curAnimation==NULL)
	{
		return;
	}
	m_curFrameTime+=msec;

	if(m_curFrameTime>m_perFrameTime)
	{
		m_curFrame++;
		m_curFrameTime-=m_perFrameTime;
	}
	if(m_curFrame>=m_totalFrame)
	{
		if(m_loop)
		{
			m_curFrame-=m_totalFrame;
		}
		else
		{
			m_curAnimation=NULL;
		}
	}
}

void SkeletonModel::draw()
{
	if(m_curAnimation!=NULL)
	{
		m_mesh->draw(m_curAnimation,m_curFrame,m_curFrame+1,m_curFrameTime/m_perFrameTime);
	}
	else
	{
		m_mesh->draw();
	}
}

void SkeletonModel::setAnimation(const FsChar* name,FsBool loop)
{
	m_curAnimation=m_mesh->getAnimation(name);
	if(m_curAnimation)
	{
		m_curFrame=0;
		m_totalFrame=m_curAnimation->getTotalFrame();
		m_curFrameTime=0;
		m_perFrameTime=m_curAnimation->getPerFrameTime();
		m_loop=loop;
	}
}



FAERIS_NAMESPACE_END 

