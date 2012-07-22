#ifndef THREE_D_MD2_H_
#define THREE_D_MD2_H_
#include<stdio.h>

#define SMD2_MAGIC_NUMBER 844121161 
#define SMD2_SKIN_NAME_LENGTH 60
extern float SMD2_LightNormals[][3];
struct SMD2Header
{
	int m_iMagicNum;      /* Magic Number:IDP2(ID Polygon 2),Hex Value is 844121161 */
	int m_iVersion;       /* Version Number,Always 8 */
	
	int m_iSkinWidthPx;   /* Texture Map Width */
	int m_iSkinHeightPx;  /* Texture Map Height */
	int m_iFrameSize;     /* Frame Size, Every Frame Size is The Same */
	int m_iNumSkins;      /* The Number Of Texture Map */
	int m_iNumVertices;   /* The Number Of Vertices For Single Frame,Every Frame Has The Same Number Of Vertices */
	int m_iNumTexCoords;  /* The Number Of Texture Coords */
	int m_iNumTriangle;   /* The Number Of Triangle */
	int m_iNumGLCommands; /* Opengl Command Used To Optimize  MD2 Mesh Rendering */
	int m_iNumFrames;     /* The Number Of Frames */

	/* All Of The Follow Is The Offset Pos */
	int m_iOffsetSkins;
	int m_iOffsetTexCoords;
	int m_iOffsetTriangles;
	int m_iOffsetFrames;
	int m_iOffsetGlCommands;

	/* The Full Size Of The MD2 File */
	int m_iFillSize;
};

struct SMD2Vert
{
	union
	{
		struct
		{
			float m_fX;
			float m_fY;
			float m_fZ;
		};
		float m_fValues[3];
	};
	unsigned short m_iNormalIndice;
};

struct SMD2Tri
{
	unsigned short m_sVertIndices[3];
	unsigned short m_sTexIndices[3];
};

struct SMD2TexCoord
{
	union{
		struct
		{
			float m_fU;
			float m_fV;
		};
		float m_fTex[2];
	};
};

struct SMD2Frame
{
	float m_fScale[3];
	float m_fTrans[3];

	char m_cName[16];
	struct SMD2Vert* m_pVerts;
};

struct SMD2Mesh
{
	struct SMD2Header* m_pHeader;
	struct SMD2Frame* m_pFrames;
	struct SMD2TexCoord* m_pTexCoords;
	struct SMD2Tri* m_pTriangles;
	char** m_pSkins;
};


struct SMD2Mesh* SMD2Mesh_Create(FILE* file);
struct SMD2Mesh* SMD2Mesh_CreateFromName(const char* name);
void SMD2Mesh_Destory(struct SMD2Mesh* sm);
void SMD2Mesh_Print(struct SMD2Mesh* sm);


struct SMD2Header* SMD2_LoadHeader(FILE* file);
void SMD2Header_Print(struct SMD2Header* h);

struct SMD2Frame* SMD2Frame_Create(unsigned short verts_nu);
void SMD2Frame_Destory(struct SMD2Frame* sf);


#endif
