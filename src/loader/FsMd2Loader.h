#ifndef _FAERIS_FSMD2_LOADER_H_
#define _FAERIS_FSMD2_LOADER_H_

#include "math/vector2.h"
#include "math/FsTexCoord2.h"
#define FS_MD2_MAGIC_NUM 844121161
#define FS_MD2_VERSION 8

FAERIS_BEGIN_NAMESPACE
class IFile;
struct Md2Header
{
	FsInt32 m_iMaigcNum;
	FsInt32 m_iVersion;
	FsInt32 m_iSkinWidthPx;
	FsInt32 m_iSkinHeightPx;
	FsInt32 m_iFrameSize;
	FsInt32 m_iNumSkins;
	FsInt32 m_iNumVertices;
	FsInt32 m_iNumTexCoords;
	FsInt32 m_iNumTriangles;
	FsInt32 m_iNumGlCommands;
	FsInt32 m_iNumFrames;
	FsInt32 m_iOffsetSkins;
	FsInt32 m_iOffsetTexCoords;
	FsInt32 m_iOffsetTriangles;
	FsInt32 m_iOffsetFrames;
	FsInt32 m_iOffsetGlCommands;
	FsInt32 m_iFileSize;
};

struct Md2Frame
{
	FsFloat m_fScale[3];
	FsFloat m_fTrans[3];
	char m_caName[16];
	Vector2* m_pVerts;
	FsUint m_iVertNu;
	Md2Frame(FsUint vertNu)
	{
		m_pVerts=new Vector2[vertNu];
		m_iVertNu=vertNu;
	}
	~Md2Frame()
	{
		delete[] m_pVerts;
	}
};

struct Md2Triangle
{
	FsUint m_iVertIndics[3];
	FsUint m_iTexIndics[3];	
};

class Md2Model
{
	public:
		Md2Mode* create(const char* filename);
		Md2Mode* create(IFile* file);
	private:
		struct Md2Frame* m_PFrames;
		FsUint m_iFrameNu;

		TexCoord2* m_pTexCoords;
		FsUint m_iTexCoordNu;

		struct Md2Triangle* m_pTriangles;
		FsUint m_iTriangleNu;
};



FAERIS_END_NAMESPACE 
#endif /*_FAERIS_FSMD2_LOADER_H_*/

