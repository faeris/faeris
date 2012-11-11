#ifndef _FAERIS_FONT_H_
#define _FAERIS_FONT_H_ 

#define FS_FONT_HINTING_NONE   0
#define FS_FONT_HINTING_LIGHT 1
#define FS_FONT_HINTING_MONO 2

#define FS_LAYOUT_HORIZONTAL 1
#define FS_LAYOUT_VERTICAL 2

FAERIS_NAMESPACE_BEGIN
class Font 
{
	public:
	protected:
		FsInt getKerningSize(FsInt prev_index,FsInt index);
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_FONT_H_*/

