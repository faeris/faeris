#ifndef _FAERY_GEOMETRY_H_
#define _FAERY_GEOMETRY_H_
#include <vector>
#include "FsMacros.h"
#include "math/FsVector3.h"
#include "graphics/FsColor.h"
#include "graphics/FsTexCoord2.h"
#include "graphics/FsBoundingBox.h"
#include "graphics/FsboundingSphere.h"
FAERIS_BEGIN_NAMESPACE
class Geometry
{
	public:
		std::vector<Vector3> vectices;
		std::vector<Vector3> normals;
		std::vector<Color> colors;
		std::vector<TexCoord2> texCoords;
		std::vector<Face3> faces;
		BoundingBox m_boundingBox;
		BoundingSphere m_boundingSphere;
}

class GeometryUtil
{
	public:
		static Geometry* makeSphere(FsFloat radius,FsInt slices,FsInt stacks,FsBool tex_coord=false);
		static Geometry* makeCylinder(FsFloat base_radius,FsFloat top_radius,
				FsFloat height,FsInt slices,FsInt stacks,FsBool tex_coord=false);
		static Geometry* makeDisk(FsFloat inner_radius,FsFloat outer_radius,
				FsInt slices,FsInt rings,FsBool tex_coord=false);
		static Geometry* makePartialDisk(FsFloat inner_radius,FsFloat outer_radius,
				FsInt rings,FsFloat startAngle,FsFloat sweepAngle,tex_coord=false);
		static Geometry* makeCube(FsFloat length,FsFloat width,FsFloat height,
				FsInt lslices,FsInt wslices,FsInt hslices,FsBool tex_coord=false);
		static Geometry* makePlane(FsFloat width,FsFloat height,FsInt lslices,FsInt wslices,tex_coord=false);

}
FAERIS_END_NAMESPACE
#endif /*_FAERY_GEOMETRY_H_*/

