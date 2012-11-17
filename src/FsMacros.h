#ifndef _FAERIS_MACROS_H_
#define _FAERIS_MACROS_H_
#include "FsTypes.h"

#define FS_BEGIN_NAMESPACE(name) namespace name{
#define FS_END_NAMESPACE(name) }

#define FAERIS_NAMESPACE_BEGIN FS_BEGIN_NAMESPACE(Faeris)
#define FAERIS_NAMESPACE_END  FS_END_NAMESPACE(Faeris)

#if defined(WIN32)
	#define FS_OS_WIN
#elif defined(LINUX)
	#define FS_OS_LINUX
#elif defined(ANDROID)
	#define FS_OS_ANDROID
#else
	#error "UNKOWN PLATFORM OS"
#endif


#define FS_PLATFORM_OS defined


#ifndef NULL
	#define NULL 0
#endif 


#if defined(FS_OS_WIN)
#define snprintf _snprintf
#endif 

#include<stdio.h>
#define FsStdout_Write printf

#define FS_CONDTION_ON(tag,cnd,fmt,...) \
	do{\
		if(cnd) \
		{ \
			FsStdout_Write("%s:",#tag); \
			FsStdout_Write("%s:%s:%d:",__FILE__,__FUNCTION__,__LINE__); \
			FsStdout_Write("%s:",#cnd); \
			FsStdout_Write(fmt,##__VA_ARGS__); \
			FsStdout_Write("\n"); \
		}\
	} while(0)

#define FS_MESSAGE(tag,fmt,...) \
	do{\
		FsStdout_Write("%s:",#tag); \
		FsStdout_Write("%s:%s:%d:",__FILE__,__FUNCTION__,__LINE__); \
		FsStdout_Write(fmt,##__VA_ARGS__); \
		FsStdout_Write("\n"); \
	} while(0)

#define FS_TRACE_WARN_ON(cnd,fmt,...) \
	FS_CONDTION_ON(WARN_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_TRACE_ERROR_ON(cnd,fmt,...) \
	FS_CONDTION_ON(ERROR_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_TRACE_INFO_ON(cnd,fmt,...) \
	FS_CONDTION_ON(INFO_ON,cnd,fmt,##__VA_ARGS__) 


#define FS_TRACE_WARN(fmt,...) \
	FS_MESSAGE(WARN,fmt,##__VA_ARGS__)

#define FS_TRACE_ERROR(fmt,...) \
	FS_MESSAGE(ERROR,fmt,##__VA_ARGS__)

#define FS_TRACE_INFO(fmt,...) \
	FS_MESSAGE(INFO,fmt,##__VA_ARGS__)

#endif /*_FAERIS_MACROS_H_*/

