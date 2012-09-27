#ifndef FY_MATH_MATRIX_H_
#define FY_MATH_MATRIX_H_ 
#include"core/vector3.h"
#include"core/vector4.h"

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
		static Matrix4 makeRotateX(float theta);
		static Matrix4 makeRotateY(float theta);
		static Matrix4 makeRotateZ(float theta);
		static Matrix4 makeRotateAxis(const Vector3& v,float angle);
		static Matrix4 makeScale(float x,float y,float z);
		static Matrix4 makeFrustum(float left,float right,float bottom,float top,float near,float far);
		static Matrix4 makePerspective(float fov,float aspect,float near,float far);
		static Matrix4 makeOrthographic(float left,float right,float top,float bottom,float neay,float far);

		Matrix4();
		Matrix4(const float* v);

		Matrix4(float v00,float v01,float v02,float v03,
				float v10,float v11,float v12,float v13,
				float v20,float v21,float v22,float v23,
				float v30,float v31,float v32,float v33)
		{
			set(v00,v01,v02,v03,
				v10,v11,v12,v13,
				v20,v21,v22,v23,
				v30,v31,v32,v33,
			   );
		}

		void add(const Matrix44& n); 
		void mul(const Matrix44& n);
		void mulScaler(float s);

		void transpose();
		void indentity();

		void setPosition(x,y,z);
		void setPosition(const Vector3& v);

		Vector3 getColumnX();
		Vector3 getColumnY();
		Vector3 getColumnZ();
		Vector3 getPosition();

		float getDetermiant();
		Matrix4 getInverse();

		void setRotationFromEuler(int type,float rx,float ry,float rz);
		void setRotationFromQauternion(); /*TODO*/
		void compose(const Vector3& translation,float rx,float ry,float rz,float s);
		void decompose(Vector3* translation,float* rx,float* ry,float* rz,float* s);



		void translate(const Vector3& v);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);

		void rotateByAxis(const Vector3& v,angle);
		void scale(const Vector3& v);

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
#endif 

