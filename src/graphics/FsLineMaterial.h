#ifndef _FAERIS_LINE_MATERIAL_H_
#define _FAERIS_LINE_MATERIAL_H_
#include "FsMacros.h"
#include "graphics/FsMaterial.h"
#include "graphics/FsColor.h"

FAERIS_NAMESPACE_BEGIN
class LineBasicMaterial:public Material
{
	public:
		Color color;
		FsFloat lineWidth;
		FsInt lineCap;
		FsInt lineJoin;
		FsBool vertexColors;
		FsBool fog;
	public:
		LineBasicMaterial()
			:lineWidth(1),lineCap(FS_LINE_CAP),lineJoin(FS_LINE_CAP),
			vertexColors(false),fog(true){}
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_LINE_MATERIAL_H_*/

