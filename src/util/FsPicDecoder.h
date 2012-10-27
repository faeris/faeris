#ifndef _FAERIS_PICTURE_DECODER_H_
#define _FAERIS_PICTURE_DECODER_H_
#include "FsMacros.h"


FAERIS_NAMESPACE_BEGIN
class Image2d;
class FsFile;

Image2d* FsUtil_DecodeJpeg(FsFile* file);
Image2d* FsUtil_DecodePng(FsFile* file);
Image2d* FsUtil_DecodeBmp(FsFile* file);


FAERIS_NAMESPACE_END

#endif /*_FAERIS_PICTURE_DECODER_H_*/

