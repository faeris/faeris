#ifndef _FAERIS_RESOURCE_MANAGER_H_
#define _FAERIS_RESOURCE_MANAGER_H_
#include "FsMacros.h"
#include <vector>
#include "util/FsDict.h"
#include "FsObject.h"

FAERIS_NAMESPACE_BEGIN

class ResourceManager
{
	public:
		void addSearchPath(const char* path);
		void removeSearchPath(const char* path);

		FsObject* getObject(const char* name);
		FsInt addObject(const char* name,FsObject* object);
		FsInt removeObject(FsObject*);

		FsInt objectUsedCnt(FsObject*);

	protected:
		std::vector<std::string> m_paths;
		FsDict m_mapNameObjet;
		FsDict m_mapObjectName;

}

FAERIS_NAMESPACE_END
#endif /*_FAERIS_RESOURCE_MANAGER_H_*/

