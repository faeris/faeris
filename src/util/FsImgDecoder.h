#ifndef _FAERIS_PICTURE_DECODER_H_
#define _FAERIS_PICTURE_DECODER_H_
#include "FsMacros.h"


FAERIS_NAMESPACE_BEGIN
class Image2D;
class FsFile;

Image2D* FsUtil_JpegReader(FsFile* file);
FsInt FsUtil_JpegWriter(FsFile* file,Image2D* img);

Image2D* FsUtil_PngReader(FsFile* file);
FsInt FsUtil_PngWriter(FsFile* file,Image2D* img);

Image2D* FsUtil_BmpReader(FsFile* file);
FsInt FsUtil_BmpWriter(FsFile* file,Image2D* img);


FAERIS_NAMESPACE_END

#endif /*_FAERIS_PICTURE_DECODER_H_*/

