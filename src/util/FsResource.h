#ifndef _FS_RESOURCE_H_
#define _FS_RESOURCE_H_ 
#include <string>

#include "FsMacros.h"
#include "FsObject.h"

FAERIS_NAMESPACE_BEGIN 

class ResourceMgr;
class Resource :public FsObject
{
	public:
		friend ResourceMgr;
	public:
		Resource();
		virtual ~Resource;
	protected:
		virtual void onDestroy();
		void setMgr(ResourceMgr* mgr){m_mgr=mgr;}
		void setName(const FsChar* name){m_resourceName=std::string(name);}
	private:
		ResourceMgr* m_mgr;
		std::string m_resourceName;
};
FAERIS_NAMESPACE_END

#endif /*_FS_RESOURCE_H_*/

