#ifndef _FAERIS_MATERIAL_H_
#define _FAERIS_MATERIAL_H_ 
#include <string>
#include "FsMacros.h"
#include "core/FsObject.h"
FAERIS_NAMESPACE_BEGIN
class Material:public FsObject 
{
	public:
		enum MaterialType
		{
			FS_MATERIAL_BASE=0,
			FS_MATERIAL_LINE,
			FS_MATERIAL_MESH,
		};
	public:
		std::string name;

		FsInt frontSide;

		FsFloat opacity;
		FsBool transparent;


		FsBool blending;
		FsInt blendSrc;
		FsInt blendDst;
		FsInt blendEquation;

		FsBool depthTest;
		FsBool depthMask;

		FsBool polygonOffset;
		FsFloat polygonOffsetFactor;
		FsFloat polygonOffsetUnits;

		FsBool alphaTest;
		FsBool visible;
	public:
		Material()
			:frontSide(FS_FRONT_SIDE),
			opacity(1), transparent(false),
			blending(false),blendSrc(FS_SRC_ALPHA),blendDst(FS_ONE_MINUS_SRC_ALPHA),
			blendEquation(FS_ADD_EQUATION),
			depthTest(true),depthMask(true),
			polygonOffset(false),polygonOffsetFactor(0),polygonOffsetUnits(0),
			alphaTest(false),
			visible(true) {}
	public:
		virtual MaterialType getMaterialType() const;
};


FAERIS_NAMESPACE_END

#endif /*_FAERIS_MATERIAL_H_*/

