#ifndef _FAERIS_TTF_FONT_H_
#define _FAERIS_TTF_FONT_H_
#include "graphics/FsFont.h"
#include "FsConfig.h"
#include "FsMacros.h"
#include "fsys/FsFile.h"
#ifdef FS_PLATFORM(FS_FREE_TYPE)
	struct FT_Face;
	typedef struct FT_Face FontPlatformTTF;
#else 
	#error  "unsupport platform for FontTTF"
#endif  /*FS_PLATFORM*/



FAERIS_NAMESPACE_BEGIN
class FontTTF:public Font 
{
	public:
		static FontTTF create(FsFile* file,int freefile);
	private:
		FontPlatformTTF* m_face;
		
		FsInt m_height;
		FsInt m_ascent;
		FsInt m_descent;
		FsInt m_lineSkip;
		FsInt m_kerning;


		FsFile* m_src;


};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_TTF_FONT_H_ */
