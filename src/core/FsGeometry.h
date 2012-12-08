#ifndef _FAERY_GEOMETRY_H_
#define _FAERY_GEOMETRY_H_

#include <vector>
#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "graphics/FsColor.h"
#include "graphics/FsTexCoord2.h"
#include "graphics/FsBoundingBox.h"
#include "graphics/FsboundingSphere.h"

FAERIS_BEGIN_NAMESPACE
class Geometry:public FsObject
{
	public:
		std::vector<Vector3> vertices;
		std::vector<Vector3> normals;
		std::vector<Color> colors;
		std::vector<TexCoord2> texCoords;
		std::vector<Face3> faces;

		BoundingBox m_boundingBox;
		BoundingSphere m_boundingSphere;
	public:
		Geometry(){}
	public:
		FsBool hasVertices() {return vertices.size()!=0;}
		FsBool hasNormals(){return normals.size()!=0;}
		FsBool HasColors(){return colors.size()!=0;}
		FsBool hasTexCoords{return texCoords.size()!=0;}
		FsBool hasFaces{return faces.size()!=0;}

		FsUint VerticesNu(){return vertices.size();}
		FsUint normalsNu() {return normals.size();}
		FsUint colorsNu() {return colors.size();}
		FsUint texCoordsNu() {return texCoordsNu.size();}
		FsUint facesNu(){return faces.size();}

		void pushVertex(const Vector3& v){vertices.push_back(v);}
		void pushNormal(const Vector3& n){normals.push_back(n);}
		void pushColors(const Color& c){colors.push_back(c);}
		void pushTexCoord(const TexCoord2& t){texCoords.push_back(t);}
		void pushFace(const Face3& f){faces.push(f);}

		void setVertexNu(FsInt nu){vertices.resize(nu);}
		void setNormalsNu(FsInt nu){vertices.resize(nu);}
		void setColorsNu(FsInt nu){vertices.resize(nu);}
		void setTexCoordsNu(FsInt nu){vertices.resize(nu);}
		void setFacesNu(FsInt nu){vertices.resize(nu);}

	public:
		void computeNormals();
		void computeBoundingBox();
		void computeBoundingSphere();
		void applyTransform(const Matrix4& mat);
};

class GeometryUtil
{
	enum GeometryType
	{
		FS_GEOMETRY_UNKOWN=0,
		FS_GEOMETRY_GTY,
	};
	public:
		static Geometry* loadFromMgr(const char* name,GeometryType=FS_GEOMETRY_UNKOWN);
		static Geometry* loadGeometry(FsFile* file,GeometryType=FS_GEOMETRY_UNKOWN);
		GeometryType GetFileType(const char* name);
	protected:
		static Geometry* loadGTY(FsFile* file);
		static FsInt saveGTY(Geometry* gty);
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

