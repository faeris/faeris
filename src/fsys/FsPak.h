#ifndef _FAERY_PAK_H_
#define _FAERY_PAK_H_
FAERY_NAMESPACE_BEGIN
class FsIFile;
class FsPakFile;
class FsPak
{
	public:
		static FsPak* create(const FsChar* name);
		static FsPak* create(FsIFile* file);

	public:
		FsIFile* unPack(const FsChar* name);
		FsBool exist(const FsChar* name);
		FsPakIterator getIterator();
		~FsPak();
	private:
		FsPak(){}
	private:
		FsIFile* m_file;
};

FAERY_NAMESPACE_END
#endif 
