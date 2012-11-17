#ifndef FS_UTIL_LOG_H_
#define FS_UTIL_LOG_H_
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN 

class FsFile;
class FsLog
{
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

void FsUtil_Log(const FsChar* tag,const FsChar* msg,...);
void FsUtil_Log(const FsChar* fmt,...);


FAERIS_NAMESPACE_END

#endif  /*FS_UTIL_LOG_H_*/

