#ifndef _GRAPHICS_COLOR_H_
#define _GRAPHICS_COLOR_H_


typedef unsigned RGBA32;
RGBA32 RGBA32_MakeRGB(int r,int g,int b);
RGBA32 RGBA32_MakeRGBA(int r,int g,int b,int a);
RGBA32 RGBA32_MakeRGBA32FromFloats(float r,float g,float b,float a);
RGBA32 RGBA32_MakeRGBAWithOverrideAlpha(RGBA32 color,float overrideAlpha);

inline int RGBA32_RedChannel(RGBA32 color){return (color>>16)&0xff;}
inline int RGBA32_GreenChannel(RGBA32 color){return (color>>8)&0xff;}
inline int RGBA32_BlueChannel(RGBA32 color){return color&0xff;}
inline int RGBA32_AlphaChannel(RGBA32 color){return (color>>24)&0xff;}

#endif /*_GRAPHICS_COLOR_H_*/

