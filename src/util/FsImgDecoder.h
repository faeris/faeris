#ifndef _FAERIS_PICTURE_DECODER_H_
#define _FAERIS_PICTURE_DECODER_H_
#include "FsMacros.h"


FAERIS_NAMESPACE_BEGIN
class Image2D;
class FsFile;

Image2D* FsUtil_DecodeJpeg(FsFile* file);
Image2D* FsUtil_DecodePng(FsFile* file);
Image2D* FsUtil_DecodeBmp(FsFile* file);


FAERIS_NAMESPACE_END

#endif /*_FAERIS_PICTURE_DECODER_H_*/

