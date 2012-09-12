#ifndef _FAERY_IO_IFILE_H_
#define _FAERY_IO_IFILE_H_
class IFile
{
	public:
		enum
		{
			IF_SET,
			IF_CUR,
			IF_END,
		};
	public:
		virtual int read(void* buf,size_t length)=0;
		virtual int write(const void* buf,size_t length)=0;
		virtual long seek(long offset,int where)=0;
		virtual int close()=0;
		virtual ~IFile(){}

};

#endif  /*_FAERY_IO_IFILE_H_*/

