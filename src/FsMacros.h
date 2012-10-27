#ifndef _FAERIS_MACROS_H_
#define _FAERIS_MACROS_H_
#include "FsTypes.h"

#define FS_BEGIN_NAMESPACE(name) namespace name{
#define FS_END_NAMESPACE(name) }

#define FAERIS_NAMESPACE_BEGIN FS_BEGIN_NAMESPACE(Faeris)
#define FAERIS_NAMESPACE_END  FS_END_NAMESPACE(Faeris)

#define FS_PLATFORM_OS defined

#define FS_OS_LINUX

#ifndef NULL
	#define NULL 0
#endif 


#include<stdio.h>
#define FsStdout_Write printf

#define FS_CONDTION_ON(tag,cnd,fmt,...) \
	do{\
		if(cnd) \
		{ \
			FsStdout_Write("%s:",#tag); \
			FsStdout_Write("%s:%s:%d:",__FILE__,__func__,__LINE__); \
			FsStdout_Write("%s:",#cnd); \
			FsStdout_Write(fmt,##__VA_ARGS____); \
			FsStdout_Write("\n"); \
		}\
	} while(0)

#define FS_MESSAGE(tag,fmt,...) \
	do{\
		FsStdout_Write("%s:",#tag); \
		FsStdout_Write("%s:%s:%d:",__FILE__,__func__,__LINE__); \
		FsStdout_Write(fmt,##__VA_ARGS__); \
		FsStdout_Write("\n"); \
	} while(0)

#define FS_WARN_ON(cnd,fmt,...) \
	FS_CONDTION_ON(WARN_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_BUG_ON(cnd,fmt,...) \
	FS_CONDTION_ON(BUG_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_DEBUG_ON(cnd,fmt,...) \
	FS_CONDTION_ON(DEBUG_ON,cnd,fmt,##__VA_ARGS__) 


#define FS_WARN(fmt,...) \
	FS_MESSAGE(WARN,fmt,##__VA_ARGS__)

#define FS_BUG(fmt,...) \
	FS_MESSAGE(BUG,fmt,##__VA_ARGS__)

#define FS_DEBUG(fmt,...) \
	FS_MESSAGE(DEBUG,fmt,##__VA_ARGS__)

#endif /*_FAERIS_MACROS_H_*/

