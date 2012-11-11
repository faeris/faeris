#ifndef _FAERIS_TEXT_LABEL_H_
#define _FAERIS_TEXT_LABEL_H_
#include "FsMacros.h"
#include "graphics/FsNode.h"
#include "graphics/FsFont.h"

#define FS_LABEL_ALIGN_LEFT 1
#define FS_LABEL_ALIGN_CENTER 2
#define FS_LABEL_ALIGN_RIGHT 3

FAERIS_NAMESPACE_BEGIN
class Font;
class  TextLabel:public FsNode
{
	public:
		TextLabel(FsChar* label,Font* font,FsInt align=FS_LABEL_ALIGN_LEFT,FsInt layout=FS_LAYOUT_HORIZONTAL);
		~TextLabel();
	public:
		virtual FsVoid draw(Render* r);
		FsUint getWidth()const {return m_width;}
		FsUint getHeight()const {return m_height;}
		std::string getLabel()const {return m_label;}
		FsUint getAlign()const {return m_align;}
		FsVoid setAlign(FsInt align){m_align=align;}
	private:
		FsInt m_align;
		FsUint m_width;
		FsUint m_height;
		std::string m_label;
		Texture2D* m_texture;
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_TEXT_LABEL_H_ */

