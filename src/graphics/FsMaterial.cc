#include "graphics/FsMaterial.h"

FAERIS_NAMESPACE_BEGIN
MaterialType Material::getMaterialType() const
{
	return FS_MATERIAL_BASE;
}

MaterialType LineMaterial::getMaterialType() const 
{
	return FS_MATERIAL_LINE;
}
FAERIS_NAMESPACE_END

