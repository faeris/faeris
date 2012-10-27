#ifndef _FAERIS_TEX_COORD2_H_
#define _FAERIS_TEX_COORD2_H_
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN

class TexCoord2
{
	public:
		union
		{
			struct
			{
				FsFloat tu;
				FsFloat tv;
			};
			FsFloat v[2];
		};
		TexCoord2(FsFloat t_u,FsFloat t_v):tu(t_u),tv(t_v){}
		TexCoord2():tu(0),tv(0){}
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_TEX_COORD2_H_*/

