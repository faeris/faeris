#ifndef FS_UTIL_LOG_H_
#define FS_UTIL_LOG_H_
class FsLog
{
	private:
		static FsLog* ms_log;
	public:
		static void sLog(const char* tag,const char* msg,...);
	public:
		void log(const char* log,const char* msg,...);
		virtual void log(const char* log)=0;
		virtual void FsLog(){}
};

class FsStdioLog:public FsLog
{
	public:
		virtual void log(const char* log);
};

class FsFileLog:public FsLog 
{
	public:
		FsFileLog* create(const char* filename);
		virtual void log(const char* log);
		virtual ~FsFileLog();
	private:
		FsFileLog(void* data);
	private:
		void* m_data;
};



#define FS_LOG_INFO(msg,...) \
	fsLog::sLog("info",msg,#VA_ARGS);

#define FS_LOG_WARN()
#define FS_LOG_ERROR()
#define FS_LOG_INFO_ON()
#define FS_LOGON_WARN_ON()
#define FS_LOGON_ERROR_ON()

#endif  /*FS_UTIL_LOG_H_*/

