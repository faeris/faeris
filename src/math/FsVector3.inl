#ifndef FY_MATH_VECTORE3_INL_
#define FY_MATH_VECTORE3_INL_

inline Vector3::Vector3(FsFloat fx,FsFloat fy,FsFloat fz)
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
inline Vector3 Vector3::scale(FsFloat k) const 
{
	return Vector3(k*x,k*y,k*z);
}

/* u dot v 
 * =u.x*v.x+u.y*v.y+u.z*v.z
 */
inline FsFloat  Vector3::dot(const Vector3& v) const
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
	FsFloat rx=y*u.z-z*u.y;
	FsFloat ry=z*u.x-x*u.z;
	FsFloat rz=x*u.y-u.x*y;
	return  Vector3(rx,ry,rz);
}

/* normal(v)= v/|v| */
inline Vector3 Vector3::normal() const
{
	FsFloat l=length();
	return Vector3(x/l,y/l,z/l);
}



inline FsVoid Vector3::normalize()
{
	FsFloat l=length();
	x=x/l;
	y=y/l;
	z=z/l;
}

/* project(u,v)= (dot(u,v)*u)/(|u||u|) */
inline Vector3 Vector3::proj(const Vector3& v) const 
{
	FsFloat l=v.x*v.x+v.y*v.y+v.z*v.z;
	FsFloat k=this->dot(v)/(l);
	return v.scale(k);
}

inline FsFloat Vector3::angle(const Vector3& v) const 
{
	FsFloat m=dot(v)/(length()*v.length());
	return Math::acos(m)/PI*180.0;
}

/* |u|=sqrt(x*x+y*y+z*z) */
inline FsFloat Vector3::length() const 
{
	FsFloat l=x*x+y*y+z*z;
	return Math::sqrt(l);
}

inline FsFloat Vector3::length2()const
{
	return x*x+y*y+z*z;
}

inline FsBool Vector3::equal(const Vector3& v) const 
{
	return (Math::floatEqual(x,v.x)&&
			Math::floatEqual(y,v.y)&&
			Math::floatEqual(z,v.z));
}


#endif 
