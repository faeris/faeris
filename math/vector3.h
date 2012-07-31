#ifndef FY_MATH_VECTORE3_H_
#define FY_MATH_VECTORE3_H_
class Vector3
{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float v[3];
		};
	public:
		Vector3(float x,float y,float z);
		Vector3();
		Vector3 add(const Vector3& v) const ;
		Vector3 sub(const Vector3& v) const ;
		Vector3 scale(float k) const ;
		float dot(const Vector3& v) const ;
		Vector3 cross(const Vector3& v)const;
		Vector3 normal() const ;
		void normalize() ;
		Vector3 project(const Vector3& v) const;
		float angle(const Vector3& v) const;
		float length() const;
		bool equal(const Vector3& v) const;
		void print()const ;


};
#include "vector3.inl"
#endif 

