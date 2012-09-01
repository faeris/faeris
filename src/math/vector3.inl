#ifndef FY_MATH_VECTORE3_INL_
#define FY_MATH_VECTORE3_INL_
#include<math.h>
#include"mathutil.h"
#include<stdio.h>

inline Vector3::Vector3(float fx,float fy,float fz)
	:x(fx),y(fy),z(fz) {}
inline Vector3::Vector3()
	:x(0),y(0),z(0)
{}

inline Vector3 Vector3::add(const Vector3& v) const
{
	return Vector3(x+v.x,y+v.y,z+v.z);
}
inline Vector3 Vector3::sub(const Vector3& v) const 
{
	return Vector3(x-v.x,y-v.y,z-v.z);
}
inline Vector3 Vector3::scale(float k) const 
{
	return Vector3(k*x,k*y,k*z);
}

/* u dot v 
 * =u.x*v.x+u.y*v.y+u.z*v.z
 */
inline float  Vector3::dot(const Vector3& v) const
{
	return x*v.x+y*v.y+z*v.z;
}

/* u cross v 
 * | i   j   k  |
 * | vx  vy  vz |
 * | ux  uy  uz |
 *
 * =(vy*uz-vz*uy)i
 * +(vz*ux-vx*uz)j
 * +(vx*uy-ux*vy)k
 */
inline Vector3 Vector3::cross(const Vector3& u) const 
{
	float rx=y*u.z-z*u.y;
	float ry=z*u.x-x*u.z;
	float rz=x*u.y-u.x*y;
	return  Vector3(rx,ry,rz);
}

/* normal(v)= v/|v| */
Vector3 Vector3::normal() const
{
	float l=length();
	return Vector3(x/l,y/l,z/l);
}



void Vector3::normalize()
{
	float l=length();
	x=x/l;
	y=y/l;
	z=z/l;
}

/* project(u,v)= (dot(u,v)*u)/(|u||u|) */
inline Vector3 Vector3::proj(const Vector3& v) const 
{
	float l=v.x*v.x+v.y*v.y+v.z*v.z;
	float k=this->dot(v)/(l);
	return v.scale(k);
}

inline float Vector3::angle(const Vector3& v) const 
{
	float m=dot(v)/(length()*v.length());
	return acos(m)/PI*180;
}

/* |u|=sqrt(x*x+y*y+z*z) */
inline float Vector3::length() const 
{
	float l=x*x+y*y+z*z;
	return sqrt(l);
}

inline float Vector3::length2()const
{
	return x*x+y*y+z*z;
}

inline bool Vector3::equal(const Vector3& v) const 
{
	return (float_equal(x,v.x)&&float_equal(y,v.y)&&float_equal(z,v.z));
}
inline void Vector3::Vector3::print() const 
{
	printf("(%f,%f,%f)\n",x,y,z);
}


#endif 
