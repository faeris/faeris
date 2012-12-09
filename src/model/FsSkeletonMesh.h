#ifndef _FS_SKELETON_MESH_H_
#define _FS_SKELETON_MESH_H_
#include <string>
#include <vector>
#include "FsMacros.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "graphics/FsMaterial.h"
#include "util/FsResource.h"
#include "util/FsResourceMgr.h"

FAERIS_NAMESPACE_BEGIN

class SkeletonVertex
{
	FsUint weightIndex;
	FsUint weightNu;
	TexCoord2 texCoord2; 
	Vector3 normal;
	Vector3 position;
};

class SkeletonWeight
{
	FsUint jointIndex;
	FsFloat weightValue;
	Vector3 position;
};

class SkeletonSubMesh
{
	public:
		FsUint materialIndex;
		std::vector<SkeletonVertex> vertics;
		std::vector<Face3> face3s;
		std::vector<SkeletonVertex> weights;
	public:
		FsUint getVectexNu()const{return vertics.size();}
		FsUint getFace3Nu()const{return face3s.size();}
		FsUint getWeghtNu()const{return weights.size();}
};

class SkeletonJoint
{
	public:
		std::string name;
		FsInt parentIndex;
		Vector3 position;
		Quaternion orientation;
};


class SkeletonMesh:public Resource
{
	public:
		static SkeletonMesh* loadFromMgr(const FsChar* filename);
		static SkeletonMesh* create(FsFile* file);
	public:
		void draw();
		void draw(SkeletonAnimation* anim,FsUint cur,FsUint next,FsFloat interp);
	public:
		void addAnimation(const FsChar* name,SkeletonAnimation* anim);
		void removeAnimation(const FsChar* name);
		SkeletonAnimation* getAnimation(const FsChar* name);
	private:
		std::vector<SkeletonJoint> m_joints;
		std::vector<SkeletonSubMesh*> m_subMeshes;
		std::vector<Material*> m_materials;
		std::hash<std::string,SkeletonAnimation*> m_animations;
};


class SkeletonMeshUtil 
{
	public:
		/* load SkeletonMesh from file with  postfix is *.skt */
		static SkeletonMesh* loadSkt(FsFile* file);

		/* load SkeletonAnimation from file with postfix is *.sanim */
		static SkeletonAnimation* loadSanim(FsFile* file);

		/* load SkeletonMesh from file with postfix is *.smesh */
		static SkeletonMesh* loadSmesh(FsFile* file);
};

FAERIS_NAMESPACE_END 

#endif /*_FS_SKELETON_MESH_H_*/



























