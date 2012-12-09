#include "model/FsSkeletonMesh.h"

FAERIS_NAMESPACE_BEGIN 
static ResourceMgr* s_skeleton_mesh_mgr=NULL;

SkeletonMesh::create(FsFile* file)
{
	SkeletonMesh* mesh=SkeletonMeshUtil::loadSkt(file);
	if(mesh==NULL)
	{
		FS_TRACE_WARN("Create SkeletonMesh Failed");
		return NULL;
	}
	return mesh;
}


SkeletonMesh::loadFromMgr(const FsChar* filename)
{
	if(s_skeleton_mesh_mgr==NULL)
	{
		s_skeleton_mesh_mgr=new ResourceMgr((ResourceMgr::NeedCreateFunc)SkeletonMesh::create);
	}
	SkeletonMesh* mesh=(SkeletonMesh*)s_skeleton_mesh_mgr->load(filename);
	return mesh;
}

FAERIS_NAMESPACE_END 



