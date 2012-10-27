#ifndef FY_MATH_VECTOR2_INL_
#define FY_MATH_VECTOR2_INL_
inline Vector2::Vector2(FsFloat fx,FsFloat fy)
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

inline Vector2 Vector2::scale(const FsFloat k)const 
{
	return Vector2(x*k,y*k);
}
inline FsFloat Vector2::dot(const Vector2& v)const 
{
	return x*v.x+y*v.y;
}

inline Vector2 Vector2::normal()const 
{
	FsFloat l=length();
	return Vector2(x/l,y/l);
}

inline FsVoid Vector2::normalize()
{
	FsFloat l=length();
	x=x/l;
	y=y/l;
}
inline Vector2 Vector2::proj(const Vector2& v) const
{
	FsFloat l=v.length2();
	FsFloat k=this->dot(v)/l;
	return v.scale(k);
}
inline FsFloat Vector2::angle(const Vector2& v) const
{
	FsFloat theta=dot(v)/(length()*v.length());
	return Math::acos(theta)/PI*180.0;
}
inline FsFloat Vector2::length() const 
{
	return Math::sqrt(length2());
}
inline FsFloat Vector2::length2()const 
{
	return x*x+y*y;
}

inline FsBool Vector2::equal(const Vector2& v) const 
{
	return Math::floatEqual(x,v.x)&&Math::floatEqual(y,v.y);
}

#endif






