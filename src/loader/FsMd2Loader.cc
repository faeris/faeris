#include "FsMd2Loader.h"
#include "fsys/FsFile.h"
#include "fsys/FsVFS.h"
#include "string.h"
#define FS_MD2_SKIN_NAME_LEN 64

FAERIS_NAMESPACE_BEGIN
Md2Model* Md2Model::create(const char* filename)
{
	FsFile* f=VFS::open(filename);
	if(f==NULL)
	{
		return NULL;
	}
	else
	{
		Md2Model* md=create(f);
		delete f;
		return md;
	}
}
Md2Model* Md2Model::create(FsFile* file)
{
	Md2Header md2_header;
	file->seek(0,FsFile::SK_SET);
	FsLong readbyte=file->read(&md2_header,sizeof(md2_header));
	if(readbyte<(FsLong)sizeof(md2_header))
	{
		FS_WARN("Invailed File Length(%ld)",readbyte);
		return NULL;
	}
	file->seek(0,FsFile::SK_END);
	FsLong file_len=file->tell();

	if(file_len!=md2_header.m_iFileSize)
	{
		FS_WARN("Invailed File Size(%ld),Expect(%u)",file_len,md2_header.m_iFileSize);
		return NULL;
	}

	if(md2_header.m_iMaigcNum!=FS_MD2_MAGIC_NUM||md2_header.m_iVersion!=FS_MD2_VERSION)
	{
		FS_WARN("Not Md2 File Format");
		return NULL;
	}
	Md2Model* md=new Md2Model(&md2_header,file);
	return md;
}

Md2Model::Md2Model(struct Md2Header* h,FsFile* file)
{
	loadFrames(h,file);
	loadTexCoords(h,file);
	loadTriangles(h,file);
	loadSkins(h,file);
}
struct Md2Vectex
{
	FsUchar x,y,z;
	FsUchar normal;
};

	
void Md2Model::loadFrames(struct Md2Header* h,FsFile* file)
{
	m_iVertexNu=h->m_iNumVertices;
	m_iFrameNu=h->m_iNumFrames;
	m_pFrames=new Md2Frame[m_iFrameNu];
	struct 
	{
		FsFloat sx,sy,sz;
		FsFloat tx,ty,tz;
		FsChar name[16];
	}frame_header;

	Md2Vectex* vertex=new Md2Vectex[m_iVertexNu];

	file->seek(h->m_iOffsetFrames,FsFile::SK_SET);
	for(FsUint i=0;i<m_iFrameNu;i++)
	{
		Md2Frame* cur_frame=m_pFrames+i;
		file->read(&frame_header,sizeof(frame_header));
		file->read(vertex,m_iVertexNu*sizeof(Md2Vectex));

		memcpy(cur_frame->m_caName,frame_header.name,16);
		cur_frame->m_pVerts= new Vector3[m_iVertexNu];

		for(FsUint j=0;j<m_iVertexNu;j++)
		{
			Vector3* cur_vec=cur_frame->m_pVerts+j;
			cur_vec->x=vertex[j].x*frame_header.sx+frame_header.tx;
			cur_vec->y=vertex[j].y*frame_header.sy+frame_header.ty;
			cur_vec->z=vertex[j].z*frame_header.sz+frame_header.tz;
		}
	}
	delete[] vertex;
}

void Md2Model::loadTexCoords(struct Md2Header* h,FsFile* file)
{
	/* load texCoords */
	m_iTexCoordNu=h->m_iNumTexCoords;
	m_pTexCoords=new TexCoord2[m_iTexCoordNu];
	file->seek(h->m_iOffsetTexCoords,FsFile::SK_SET);
	file->read(m_pTexCoords,sizeof(TexCoord2)*m_iTexCoordNu);
}
void Md2Model::loadTriangles(struct Md2Header* h,FsFile* file)
{
	/* load trangles */
	m_iTriangleNu=h->m_iNumTriangles;
	m_pTriangles=new Md2Triangle[m_iTriangleNu];
	file->seek(h->m_iOffsetTriangles,FsFile::SK_SET);
	file->read(m_pTriangles,sizeof(Md2Triangle)*m_iTriangleNu);
}
void Md2Model::loadSkins(struct Md2Header* h,FsFile* file)
{
	m_iSkinWidthPx=h->m_iSkinWidthPx;
	m_iSkinHeightPx=h->m_iSkinHeightPx;

	m_iSkinNu=h->m_iNumSkins;
	m_pSkinName=new FsChar*[m_iSkinNu];
	file->seek(h->m_iOffsetSkins,FsFile::SK_SET);

	for(FsUint i=0;i<m_iSkinNu;i++)
	{
		FsChar* cur_name=m_pSkinName+i;
		cur_name=new char[FS_MD2_SKIN_NAME_LEN];
		file->read(cur_name,FS_MD2_SKIN_NAME_LEN);
	}
}

FAERIS_NAMESPACE_END

