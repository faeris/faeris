#ifndef FY_MATH_MATRIX_H_
#define FY_MATH_MATRIX_H_ 

class  Matrix44
{
	public:
		union{
			struct 
			{
				float m00,m01,m02,m03;
				float m10,m11,m12,m13;
				float m20,m21,m22,m23;
				float m30,m31,m32,m33;
			}
			float v[16];
			float m[4][4];
		};

	public:
		static Matrix44 fromAngleX(float theta);
		static Matrix44 fromAngleY(float theta);
		static Matrix44 fromAngleZ(float theta);
		static Matrix44 fromTranslate(float x,float y,float z);

		Matrix44();
		Matrix44(const float* v);

		Matrix44 add(const Matrix44& n) const;
		Matrix44 sub(const Matrix44& n) const;
		Matrix44 mulQuantity( const Matrix44& n) const;
		Matrix44 mul(const Matrix44& n) const;

};
#endif 

