#ifndef _FS_MATH_MATRIX4_H_
#define _FY_MATH_MATRIX4_H_ 
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsQuaternion.h"

#define FS_EULER_XYZ (0x1)
#define FS_EULER_XZY (0x2)
#define FS_EULER_YXZ (0x3)
#define FS_EULER_YZX (0x4) 
#define FS_EULER_ZXY (0x5)
#define FS_EULER_ZYX (0x6)

FAERIS_NAMESPACE_BEGIN
class  Matrix4
{
	public:
		union{
			struct 
			{
				float m00,m01,m02,m03;
				float m10,m11,m12,m13;
				float m20,m21,m22,m23;
				float m30,m31,m32,m33;
			};
			float v[16];
			float m[4][4];
		};
	public:

		Matrix4(){}
		Matrix4(const float* v);

		Matrix4(float v00,float v01,float v02,float v03,
				float v10,float v11,float v12,float v13,
				float v20,float v21,float v22,float v23,
				float v30,float v31,float v32,float v33)
		{
			set(v00,v01,v02,v03,
				v10,v11,v12,v13,
				v20,v21,v22,v23,
				v30,v31,v32,v33
			   );
		}


		/* normal operating for Matrix4 */
		void add(const Matrix4& n); 
		void mul(const Matrix4& n);
		void mulScaler(float s);

		void transpose();
		void getTranspose(Matrix4* m);
		void inverse();
		void getInverse(Matrix4* m);
		float getDetermiant();


		/* aux function to quick change Matrix4  */
		void makeRotateX(float theta);
		void makeRotateY(float theta);
		void makeRotateZ(float theta);
		void makeRotateAxis(const Vector3& v,float angle);
		void makeScale(float x,float y,float z);
		void makeFrustum(float left,float right,float bottom,float top,float near,float far);
		void makePerspective(float fov,float aspect,float near,float far);
		void makeOrthographic(float left,float right,float top,float bottom,float neay,float far);
		void makeIdentity();


		/* set rotate,scale and translate part in Matrix4 */
		void setRotationFromEuler(float rx,float ry,float rz,int type);
		void setRotationFromQuaternion(const Quaternion& q); 
		void setScale(float sx,float sy,float sz);
		void setScale(const Vector3& v){setScale(v.x,v.y,v.z);}
		void setTranslate(float x,float y,float z);
		void setTranslate(const Vector3& v){setTranslate(v.x,v.y,v.z);}

		/* transform rotate,scale,translate part in Matrix4 */
		void translate(const Vector3& v);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		void rotateByAxis(const Vector3& v,float angle);
		void scale(const Vector3& v);

		
		/* get rotate,scale,and translate information from Matrix4 */
		void getColumnX(Vector3* v);
		void getColumnY(Vector3* v);
		void getColumnZ(Vector3* v);
		void getTranslate(Vector3* v);
		void getScale(Vector3* v);
		void getRotate(Quaternion* q);

	protected:
		void set(float v00,float v01,float v02,float v03,
				float v10,float v11,float v12,float v13,
				float v20,float v21,float v22,float v23,
				float v30,float v31,float v32,float v33)
		{
			m00=v00;m01=v01;m02=v02;m03=v03;
			m10=v10;m11=v11;m12=v12;m13=v13;
			m20=v20;m21=v21;m22=v22;m23=v23;
			m30=v30;m31=v31;m32=v32;m33=v33;
		}
};
FAERIS_NAMESPACE_END
#endif 

