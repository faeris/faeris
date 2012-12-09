#include "util/FsResourceMgr.h"
#include "util/FsResource.h"

FAERIS_NAMESPACE_BEGIN
ResourceMgr::ResourceMgr(NeedCreateFunc func)
{
	m_func=func;
}
void ResourceMgr::addSearchPath(const char* path)
{
	std::vector<std::string>::iterator iter;
	iter=m_searchPath.begin();
	std::string add_path=std::string(path);
	if(add_path.size()>=1)
	{
		if(add_path[add_path.size()-1]!='/')
		{
			add_path+=std::string("/");
		}
	}
	else
	{
		return ;
	}

	for(;iter!=m_searchPath.end();++iter)
	{
		if((*iter)==add_path)
		{
			FS_TRACE_WARN("Search Path(%s) Already Add",path);
			return;
		}
	}

	m_searchPath.push_back(add_path);
}

void ResourceMgr::removeSearchPath(const char* path)
{
	std::vector<std::string>::iterator iter;
	iter=m_searchPath.begin();
	std::string remove_path=std::string(path);

	for(;iter!=m_searchPath.end();++iter)
	{
		if((*iter)==remove_path)
		{
			m_searchPath.erase(iter);
			return;
		}
	}
	FS_TRACE_WARN("Can't Find Search Path(%s)",path);
}

Resource* ResourceMgr::load(const char* path)
{
	std::string key_path=std::string(path);
	Resource* ret=m_resources[key_path];
	FsFile* file=NULL;
	if(ret!=NULL)
	{
		ret->addRef();
		return ret;
	}
	if(!m_func)
	{
		FS_TRACE_WARN("Can't Load Source From Path(%s)",path);
		return NULL;
	}

	/* Open Current Path */
	file=VFS::open(key_path);
	if(file!=NULL)
	{
		ret=m_func(file);
		delete file;
		if(ret!=NULL)
		{
			m_resources[key_path]=ret;
			ret->setName(key_path.c_str());
			ret->setMgr(this);
			return ret;
		}
	}
	file=NULL;

	/* Search File In Register Path */
	std::vector<std::string>::iterator iter;
	iter=m_searchPath.begin();
	for(;iter!=m_searchPath.end();++iter)
	{
		std::string new_path=(*iter)+key_path;
		FsFile* file=VFS::open(new_path.c_str());
		if(file!=NULL)
		{
			ret=m_func(file);
			delete file;
			if(ret!=NULL)
			{
				m_resources[key_path]=ret;
				ret->setName(key_path.c_str());
				ret->setMgr(this);
				return ret;
			}
		}
	}

	FS_TRACE_WARN("Can't Load Source From Path(%s)",path);
}

void ResourceMgr::remove(Resource* res)
{
	FS_ASSERT(res->m_mgr==this);
	FsInt ret=m_resources.erase(res->m_resourceName);
	FS_ASSERT(ret==1);
}


FAERIS_NAMESPACE_END

