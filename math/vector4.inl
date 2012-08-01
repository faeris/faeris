#ifndef FY_MATH_VECTOR4_INL_
#define FY_MATH_VECTOR4_INL_
#include"vector4.h"
#include"mathutil.h"
#include"math.h"

inline Vector4::Vector4(float fx,float fy,float fz,float fw)
	:x(fx),y(fy),z(fz),w(fw)
{}

inline Vector4::Vector4(float fx,float fy,float fz)
	:x(fx),y(fy),z(fz),w(1)
{}
inline Vector4::Vector4()
	:x(0),y(0),z(0),w(1)
{}

inline Vector4 Vector4::add(const Vector4& v) const 
{
	return Vector4(x+v.x,y+v.y,z+v.z,w+v.w);
}

inline Vector4 Vector4::sub(const Vector4& v) const 
{
	return Vector4(x-v.x,y-v.y,z-v.z,w-v.w);
}

inline Vector4 Vector4::scale(float k) const 
{
	return Vector4(x*k,y*k,z*k,w*k);
}

inline float Vector4::dot(const Vector4& v)const 
{
	return x*v.x+y*v.y+z*v.z+w*v.w;
}

inline Vector4 Vector4::normal() const 
{
	float l=length();

	return Vector4(x/l,y/l,z/l,w/l);
}

inline void Vector4::normalize() 
{
	float l=length();
	x=x/l;
	y=y/l;
	z=z/l;
	w=w/l;
}


inline float Vector4::length() const 
{
	return sqrt(length2());
}

inline float Vector4::length2() const 
{
	return x*x+y*y+z*z+w*w;
}

inline bool Vector4::equal(const Vector4&  v) const 
{
	return float_equal(x,v.x)&&float_equal(y,v.y)&&float_equal(z,v.z)&&float_equal(w,v.w);
}

inline void Vector4::print() const 
{
	printf("(%f,%f,%f,%f)\n",x,y,z,w);
}


#endif 



