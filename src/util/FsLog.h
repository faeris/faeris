#ifndef FS_UTIL_LOG_H_
#define FS_UTIL_LOG_H_
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN 

class FsFile;
class FsLog
{
	private:
		static FsLog* ms_log;
		static void init();
	public:
		static void sLog(const FsChar* tag,const FsChar* msg,...);
		static void sLog(const FsChar* fmt,...);

	public:
		void log(const FsChar* tag,const FsChar* fmt,...);
		void log(const FsChar* fmt,...);

		virtual ~FsLog(){}
	protected:
		virtual void logMsg(const FsChar* log)=0;

};

class FileLog:public FsLog 
{
	public:
		static FileLog* getStdoutFileLog();
		static FileLog* ms_stdoutFileLog;
		static FileLog* create(const FsChar* filename);
	public:
		virtual ~FileLog();
	protected:
		virtual void logMsg(const FsChar* log);
	private:
		FileLog(FsFile* file);
	private:
		FsFile* m_file;
};


#define FS_LOG_INFO(fmt,...) 

#define FS_LOG_WARN(fmt,...)
#define FS_LOG_DEBUG(fmt,...)
#define FS_LOG_ERROR(fmt,...)
#define FS_LOG_INFO_ON(conditon,fmt,...)
#define FS_LOGON_WARN_ON()
#define FS_LOGON_ERROR_ON()

FAERIS_NAMESPACE_END

#endif  /*FS_UTIL_LOG_H_*/

