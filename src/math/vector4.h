#ifndef FY_MATH_VECTOR4_H_
#define FY_MATH_VECTOR4_H_

class Vector4
{
	public:
		union
		{
			struct 
			{
				float x;
				float y;
				float z;
				float w;
			};
			float v[4];
		};
	public:
		Vector4(float fx,float fy,float fz,float fw);
		Vector4(float fx,float fy,float fz);
		Vector4();
		Vector4 add(const Vector4& v)const ;
		Vector4 sub(const Vector4& v)const;
		Vector4 scale(float k)const ;
		float dot(const Vector4& v)const;

		Vector4 normal() const ;
		void normalize() ;
		float length() const;
		float length2() const;

		bool equal(const Vector4& v) const;
		void print()const;
};

#include"vector4.inl"
#endif



