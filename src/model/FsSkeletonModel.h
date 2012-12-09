#ifndef _FS_SKELETON_MODEL_H_
#define _FS_SKELETON_MODEL_H_
#include <vector>

#include "FsMacros.h"
#include "FsObject.h"

FAERIS_NAMESPACE_BEGIN
class SkeletonAnimation;

class SkeletonModel:public FsObject,Animation
{
	public:
		static SkeletonModel* create(const FsChar* filename);
	public:
		SkeletonModel(SkeletonMesh* mesh);
		~SkeletonModel();
	public:
		void draw();
		void setAnimation(const FsChar* name,FsBool loop=true);
		void update(FsLong msec);
	private:
		SkeletonMesh* m_mesh;
		SkeletonAnimation* m_curAnimation;

		FsUint m_curFrame;
		FsUint m_totalFrame;
		FsFloat m_curFrameTime;
		FsFloat m_perFrameTime;
		FsBool m_loop;

};


FAERIS_NAMESPACE_END 
#endif /*_FS_SKELETON_MODEL_H_*/

