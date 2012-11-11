#ifndef _FAERIS_RENDERABLE_H_
#define _FAERIS_RENDERABLE_H_

#define FS_FILL_SOLID_COLOR 1
#define FS_FILL_TEXTURE 2

FAERIS_NAMESPACE_BEGIN
class Render;
class Renderable
{
	public:
		virtual void draw(Render* r);
		~virtual Renderable(){}

};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_RENDERABLE_H_*/

