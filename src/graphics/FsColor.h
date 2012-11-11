#ifndef _FAERIS_COLOR_H_
#define _FAERIS_COLOR_H_
#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN
class Color 
{
	public:
		union{
			struct{
				FsUchar r;
				FsUchar g;
				FsUchar b;
				FsUchar a;
			};
			FsUint rgba;
		};
	public:
		Color(FsUchar red,FsUchar green,FsUchar blue,FsUchar alpha)
			:r(red),g(green),b(blue),a(alpha){}
		Color():r(0),g(0),b(0),a(255){}
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_COLOR_H_*/

