#include "FsMd2Loader.h"
#include "fsys/IFile.h"
#include "fsys/FsVFS.h"

FAERIS_BEGIN_NAMESPACE
Md2Model* Md2Model::create(const char* filename)
{
	IFile* f=VFS::open(filename);
	if(f==NULL)
	{
		return NULL;
	}
	else
	{
		return create(f);
	}
}
Md2Model* Md2Model::create(IFile* file)
{
	Md2Header md2_header;
	file->seek(0,IFile::IF_SET);
	FsLong readbyte=file->read(md2_header,sizeof(md2_header));
	if(readbyte<sizeof(md2_header))
	{
		FS_WARN_ON("Invailed File Length(%d)",readbyte);
		return NULL;
	}
}






	

FAERIS_END_NAMESPACE

