#ifndef _FAERY_FACE3_H_
#define _FAERY_FACE3_H_

#include "FsTypes.h"

FAERIS_BEGIN_NAMESPACE 
class Face3 
{
	public:
		union
		{
			struct
			{
				FsUint a;
				FsUint b;
				FsUint c;
			};
			FsUint v[3];
		};


}
FAERIS_END_NAMESPACE 

#endif 

