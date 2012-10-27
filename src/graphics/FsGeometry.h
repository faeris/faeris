#ifndef _FAERY_GEOMETRY_H_
#define _FAERY_GEOMETRY_H_
#include "math/FsVector3.h"
#include "graphics/FsRGBA.h"
#include "graphics/FsTexCoord2.h"
#include "FsTypes.h"
#include "graphics/FsBoundingBox.h"
#include "graphics/FsboundingSphere.h"
FAERIS_BEGIN_NAMESPACE
class Render;

class Geometry
{
	public:
		enum GeometryFlags
		{
			
		};	

	private:
		FsLong m_flags;

		Vector3* m_vectices;
		FsUlong  m_vecticesNu;

		Vector3* m_normals;
		FsUlong m_normalsNu;

		RGBA* m_colors;
		FsUlong m_colorsNu;

		TexCoord2* m_texCoords;
		FsUlong m_texCoordsNu;

		Face3* m_faces;
		FsUlong m_facesNu;

		FsUint m_vecticesBuffer;
		FsUint m_normalsBuffer;
		FsUint m_texCoordsBuffer;
		FsUint m_facesBuffer;


		
		BoundingBox m_boundingBox;
		BoundingSphere m_boundingSphere;


}
FAERIS_END_NAMESPACE

#endif /*_FAERY_GEOMETRY_H_*/

