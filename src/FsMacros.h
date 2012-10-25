#ifndef _FAERIS_MACROS_H_
#define _FAERIS_MACROS_H_

#define FS_BEGIN_NAMESPACE(name) namespace name{
#define FS_END_NAMESPACE(name) }

#define FAERIS_NAMESPACE_BEGIN FS_BEGIN_NAMESPACE(Faeris)
#define FAERIS_NAMESPACE_END  FS_END_NAMESPACE(Faeris)
#include "FsTypes.h"

#define FS_OS_LINUX

#endif /*_FAERIS_MACROS_H_*/

