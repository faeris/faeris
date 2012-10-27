#ifndef  FY_MATH_VECTOR2_H_
#define  FY_MATH_VECTOR2_H_ 

#include "FsMacros.h"
#include "FsMathUtil.h"

FAERIS_NAMESPACE_BEGIN
class Vector2
{
	public:
		union
		{
			struct 
			{
				FsFloat x;
				FsFloat y;
			};
			FsFloat v[2];
		};
	public:
		Vector2(FsFloat fx,FsFloat fy);
		Vector2();
		Vector2 add(const Vector2& v)const;
		Vector2 sub(const Vector2& v)const;
		Vector2 scale(FsFloat k) const ;
		FsFloat dot(const Vector2& v)const;
		Vector2 normal()const;
		FsVoid normalize();
		Vector2 proj(const Vector2& v)const;
		FsFloat angle(const Vector2& v)const;
		FsFloat length() const;
		FsFloat length2() const;
		FsBool equal(const Vector2& v)const ;
};

#include "FsVector2.inl"
FAERIS_NAMESPACE_END
#endif 


