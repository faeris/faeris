#ifndef FY_MATH_VECTOR2_INL_
#define FY_MATH_VECTOR2_INL_
#include "core/vector2.h"
#include "core/mathutil.h"
#include<math.h>
inline Vector2::Vector2(float fx,float fy)
	:x(fx),y(fy)
{}
inline Vector2::Vector2()
	:x(0),y(0)
{}

inline Vector2 Vector2::add(const Vector2& v) const
{
	return Vector2(x+v.x,y+v.y);
}

inline Vector2 Vector2::sub(const Vector2& v) const 
{
	return Vector2(x-v.x,y-v.y);
}

inline Vector2 Vector2::scale(const float k)const 
{
	return Vector2(x*k,y*k);
}
inline float Vector2::dot(const Vector2& v)const 
{
	return x*v.x+y*v.y;
}

inline Vector2 Vector2::normal()const 
{
	float l=length();
	return Vector2(x/l,y/l);
}

inline void Vector2::normalize()
{
	float l=length();
	x=x/l;
	y=y/l;
}
inline Vector2 Vector2::proj(const Vector2& v) const
{
	float l=v.length2();
	float k=this->dot(v)/l;
	return v.scale(k);
}
inline float Vector2::angle(const Vector2& v) const
{
	float theta=dot(v)/(length()*v.length());
	return acos(theta)/PI*180;
}
inline float Vector2::length() const 
{
	return sqrt(length2());
}
inline float Vector2::length2()const 
{
	return x*x+y*y;
}

inline bool Vector2::equal(const Vector2& v) const 
{
	return float_equal(x,v.x)&&float_equal(y,v.y);
}
inline void Vector2::print()const
{
	printf("(%f,%f)\n",x,y);
}










#endif






