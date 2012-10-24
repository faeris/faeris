#ifndef _FAERIS_TEX_COORD2_H_
#define _FAERIS_TEX_COORD2_H_
FAERIS_BEGIN_NAMESPACE
class TexCoord2.h
{
	union
	{
		struct
		{
			FsFloat u;
			FsFloat v;
		};
		FsFloat v[2];
	}
	TexCoord2(FsFloat t_u,FsFloat t_v):u(T_u),v(t_v){}
	TexCoord2();
}
FAERIS_END_NAMESPACE
#endif /*_FAERIS_TEX_COORD2_H_*/

