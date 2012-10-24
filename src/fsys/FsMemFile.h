#ifndef _FAERY_MEM_FILE_H_
#define _FAERY_MEM_FILE_H_

#include"FsIFile.h"

FAERY_NAMESPACE_BEGIN
class FsMemFile:public FsIFile
{
	public:
		FsMemFile(const FsVoid* mem,FsUlong len);
		FsMemFile();
	public:
		virtual FsLong read(FsVoid* buf,FsLong len);
		virtual FsLong write(const FsVoid* buf,FsLong len);
		virtual FsLong seek(FsLong offset,FsInt where);
		virtual FsLong tell();
		virtual FsInt close();
		virtual ~FsMemFile();
	public:
		FsInt save(const FsChar* name);
	protected:
		FsVoid ensureMore(FsUint len);
	private:
		FsChar* m_mem;
		FsUlong m_length;
		FsUlong m_cap;
		FsUlong m_pos;
};

FAERY_NAMESPACE_END

#endif /*_FAERY_MEM_FILE_H_*/

