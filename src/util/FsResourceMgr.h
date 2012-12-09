#ifndef _FS_RESOURCE_MGR_H_
#define _FS_RESOURCE_MGR_H_ 

#include <string>
#include <vector>
#include "FsMacros.h"


FAERIS_NAMESPACE_BEGIN
class Resource;
class ResourceMgr 
{
	public:
		typedef Resource* (*NeedCreateFunc)(FsFile* file);
	public:
		ResourceMgr(NeedCreateFunc func);
	public:
		void addSearchPath(const char* path);
		bool existSearchPath(const char* path);
		void removeSearchPath(const char* path);

		Resource* load(const char* path);
		void remove(Resource* res);

	private:
		NeedCreateFunc m_func;
		std::vector<std::string> m_searchPath;

		FsInt m_resNu;
		std::hash_map<std::string,Resource*> m_resources;
};
FAERIS_NAMESPACE_END
#endif  /*_FS_RESOURCE_MGR_H_*/


