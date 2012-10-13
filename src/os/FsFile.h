#ifndef _FAERY_IO_IFILE_H_
#define _FAERY_IO_IFILE_H_
class FsIFile
{
	public:
		enum
		{
			IF_SET,
			IF_CUR,
			IF_END,
		};
	public:
		virtual FsLong read(FsVoid* buf,FsLong length)=0;
		virtual FsLong write(const FsVoid* buf,FsLong length)=0;
		virtual FsLong seek(FsLong offset,FsInt where)=0;
		virtual FsInt  close()=0;
		virtual FsLong tell()=0;
		virtual ~FsIFile(){}
};

#endif  /*_FAERY_IO_IFILE_H_*/

