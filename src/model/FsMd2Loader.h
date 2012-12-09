#ifndef _FAERIS_FSMD2_LOADER_H_
#define _FAERIS_FSMD2_LOADER_H_

#include "FsMacros.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#define FS_MD2_MAGIC_NUM 844121161
#define FS_MD2_VERSION 8

FAERIS_NAMESPACE_BEGIN
class FsFile;
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
	char m_caName[16];
	Vector3* m_pVerts;
	Md2Frame():m_pVerts(NULL){}
	~Md2Frame()
	{
		if(m_pVerts)
		{
			delete[] m_pVerts;
		}
	}
};

struct Md2Triangle
{
	FsUint16 m_iVertIndics[3];
	FsUint16 m_iTexIndics[3];	
};

class Md2Model
{
	public:
		static Md2Model* create(const char* filename);
		static Md2Model* create(FsFile* file);
	private:
		Md2Model(struct Md2Header* h,FsFile* file);

		void loadFrames(struct Md2Header* h,FsFile* file);
		void loadTriangles(struct Md2Header* h,FsFile* file);
		void loadTexCoords(struct Md2Header* h,FsFile* file);
		void loadSkins(struct Md2Header* h,FsFile* file);
	public:
	//private:
		struct Md2Frame* m_pFrames;
		FsUint m_iFrameNu;
		FsUint m_iVertexNu;

		TexCoord2* m_pTexCoords;
		FsUint m_iTexCoordNu;

		struct Md2Triangle* m_pTriangles;
		FsUint m_iTriangleNu;

		FsUint m_iSkinNu;
		FsTexture* m_pTexture;
};



FAERIS_NAMESPACE_END
#endif /*_FAERIS_FSMD2_LOADER_H_*/

