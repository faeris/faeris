#ifndef FY_MATH_VECTOR4_INL_
#define FY_MATH_VECTOR4_INL_

inline Vector4::Vector4(FsFloat fx,FsFloat fy,FsFloat fz,FsFloat fw)
	:x(fx),y(fy),z(fz),w(fw)
{}

inline Vector4::Vector4(FsFloat fx,FsFloat fy,FsFloat fz)
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

inline Vector4 Vector4::scale(FsFloat k) const 
{
	return Vector4(x*k,y*k,z*k,w*k);
}

inline FsFloat Vector4::dot(const Vector4& v)const 
{
	return x*v.x+y*v.y+z*v.z+w*v.w;
}

inline Vector4 Vector4::normal() const 
{
	FsFloat l=length();

	return Vector4(x/l,y/l,z/l,w/l);
}

inline FsVoid Vector4::normalize() 
{
	FsFloat l=length();
	x=x/l;
	y=y/l;
	z=z/l;
	w=w/l;
}


inline FsFloat Vector4::length() const 
{
	return Math::sqrt(length2());
}

inline FsFloat Vector4::length2() const 
{
	return x*x+y*y+z*z+w*w;
}

inline FsBool Vector4::equal(const Vector4&  v) const 
{
	return Math::floatEqual(x,v.x)&&
		   Math::floatEqual(y,v.y)&&
		   Math::floatEqual(z,v.z)&&
		   Math::floatEqual(w,v.w);
}

#endif 



