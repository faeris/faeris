#ifndef _FAERIS_COLOR_H_
#define _FAERIS_COLOR_H_
#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN
class Color 
{
	public:
		static Color DEFAULT_COLOR;
		static Color RED;
		static Color BLUE;
		static Color GREEN;
		static Color WHITE;
		static Color BLACK;
	public:
		union{
			struct{
				FsUchar r;
				FsUchar g;
				FsUchar b;
				FsUchar a;
			};
			FsUint rgba;
		};
	public:
		Color(FsUchar red,FsUchar green,FsUchar blue,FsUchar alpha)
			:r(red),g(green),b(blue),a(alpha){}
		Color():r(0),g(0),b(0),a(255){}
		Color(FsUchar red,FsUchar green,FsUchar blue)
			:r(red),g(green),b(blue),a(255){}

		Color operator+(Color right);
		Color operator-(Color right);
		Color operator*(FsFloat s);
		bool operator==(Color right){return rgba==right.rgba;}
		bool operator!=(Color right){return rgba!=right.rgba;}
};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_COLOR_H_*/

