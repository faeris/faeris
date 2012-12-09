#ifndef _FAERY_TYPES_H_
#define _FAERY_TYPES_H_


typedef void FsVoid;
typedef char FsChar;

typedef unsigned char FsUchar;

#if defined(__cplusplus)
typedef bool FsBool;
#else 
typedef int FsBool;
#endif 

typedef char FsInt8;
typedef unsigned char FsUint8;

typedef short int FsInt16;
typedef unsigned short FsUint16;

typedef int FsInt32;
typedef unsigned int FsUint32;

typedef float FsFloat;
typedef double FsDouble;

typedef unsigned long FsUlong;
typedef long FsLong;

typedef int FsInt;
typedef unsigned int FsUint;


#endif  /*_FAERY_TYPES_H_*/

