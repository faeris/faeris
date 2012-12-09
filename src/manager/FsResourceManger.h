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

	protected:
		std::vector<std::string> m_paths;

}

FAERIS_NAMESPACE_END
#endif /*_FAERIS_RESOURCE_MANAGER_H_*/

