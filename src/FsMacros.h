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









/* global Macros For Faeris */

/* event part*/

#define FS_MOUSE_EVENT 0x1
#define FS_KEYBOARD_EVENT 0x2
#define FS_TOUCH_EVENT 0x3

#define FS_MOUSE_LEFT_BUTTON 0x1
#define FS_MOUSE_MIDDLE_BUTTON 0x2 
#define FS_MOUSE_RIGHT_BUTTON 0x3 

#define FS_DOWN 0x1 
#define FS_UP 0x2 
#define FS_CLICK 0x3 
#define FS_DCLICK 0x4
#define FS_MOVE 0x5


/* Frame Buffer */
#define FS_BUFFER_LEFT
#define FS_BUFFER_RIGHT
#define FS_BUFFER_FRONT
#define FS_BUFFER_BACK
#define FS_BUFFER_SINGLE 
#define FS_BUFFER_DOUBLE 
#define FS_BUFFER_STENCIL
#define FS_BUFFER_SAMPLES 
#define FS_BUFFER_DEPTH
#define FS_BUFFER_RGB 
#define FS_BUFFER_RGBA












#endif /*_FAERIS_MACROS_H_*/

