#include "FsColor.h"

FAERIS_NAMESPACE_BEGIN

Color Color::DEFAULT_COLOR=Color(255,255,255,255);
Color Color::RED=Color(255,0,0,255);
Color Color::BLUE=Color(0,0,255,255);
Color Color::GREEN=Color(0,255,0,255);
Color Color::WHITE=Color(255,255,255,255);
Color Color::BLACK=Color(0,0,0,255);


Color Color::operator+(Color right)
{
	FsInt red=r+right.r;
	FsInt green=g+right.g;
	FsInt blue=b+right.b;
	FsInt alpha=a+right.a;

	if(red>255) red=255;
	if(green>255) green=255;
	if(blue>255) blue=255;
	if(alpha>255) alpha=255;

	return Color(red,green,blue,alpha);
}

Color Color::operator-(Color right)
{
	FsInt red=r-right.r;
	FsInt green=g-right.g;
	FsInt blue=b-right.b;
	FsInt alpha=a-right.a;

	if(red<0) red=0;
	if(green<0) green=0;
	if(blue<0) blue=0;
	if(alpha<0) alpha=0;

	return Color(red,green,blue,alpha);
}

Color Color::operator*(FsFloat s)
{
	FsInt red=(FsInt)(r*s);
	FsInt green=(FsInt)(g*s);
	FsInt blue=(FsInt)(b*s);
	FsInt alpha=(FsInt)(a*s);

	if(red<0) red=0;
	if(red>255) red=255;

	if(green<0)  green=0;
	if(green>255) green=255;

	if(blue<0) blue=0;
	if(blue>255) blue=255;

	if(alpha<0) alpha=0;
	if(alpha>255) alpha=255;


	return Color(red,green,blue,alpha);
}

FAERIS_NAMESPACE_END

