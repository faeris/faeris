#include"md2.h"
#include<stdlib.h>
#include<utilc/marocs.h>
#include<string.h>
#include<assert.h>


/* load md2 header from md2 file */
struct SMD2Header* SMD2_LoadHeader(FILE* file)
{
	size_t readbyte=0;
	fseek(file,0,SEEK_SET);
	struct SMD2Header* header=(struct SMD2Header*)malloc(sizeof(*header));
	memset(header,0,sizeof(*header));
	if(header==NULL)
	{
		WARN("Alloc Memory For SMD2Header Failed");
		return NULL;
	}

	readbyte=fread(header,sizeof(*header),1,file);
	if(readbyte!=1)
	{
		WARN("Error File Format");
		goto error;
	}

	if(header->m_iMagicNum!=844121161&&header->m_iVersion!=8)
	{
		printf("header->m_iMagicNum=%d\n",header->m_iMagicNum);
		WARN("Error File Format");
		goto error;
	}
	return header;
error:
	free(header);
	return NULL;
}



/* from header information cal the memory for the md2 mesh */
static struct SMD2Mesh* s_smd2mesh_alloc(struct SMD2Header* h)
{
	int i;
	struct SMD2Frame* frames=NULL;
	struct SMD2TexCoord* tex_coords=NULL;
	struct SMD2Tri* triangles=NULL;
	struct SMD2Mesh* mesh=NULL;

	char** skin_name=NULL;

	mesh=(struct SMD2Mesh*) malloc(sizeof(*mesh));
	if(mesh==NULL)
	{
		goto error;
	}

	frames=(struct SMD2Frame*)malloc(sizeof(*frames)*h->m_iNumFrames);
	if(frames==NULL)
	{
		goto error;
	}
	memset(frames,0,sizeof(*frames)*h->m_iNumFrames);
	for(i=0;i<h->m_iNumFrames;i++)
	{
		frames[i].m_pVerts=(struct SMD2Vert*)malloc(sizeof(struct SMD2Vert)*h->m_iNumVertices);
		if(frames[i].m_pVerts==NULL)
		{
			goto error;
		}
	}

	triangles=(struct SMD2Tri*)malloc(sizeof(*triangles)*h->m_iNumTriangle);
	if(triangles==NULL)
	{
		goto error;
	}

	tex_coords=(struct SMD2TexCoord*)malloc(sizeof(*tex_coords)*h->m_iNumTexCoords);

	if(tex_coords==NULL)
	{
		goto error;
	}

	skin_name=(char**)malloc(h->m_iNumSkins*sizeof(char*));
	if(skin_name==NULL)
	{
		goto error;
	}
	memset(skin_name,0,h->m_iNumSkins*sizeof(char*));

	for(i=0;i<h->m_iNumSkins;i++)
	{
		skin_name[i]=(char*)malloc(SMD2_SKIN_NAME_LENGTH);
		if(skin_name[i]==NULL)
		{
			goto error;
		}
	}


	mesh->m_pFrames=frames;
	mesh->m_pHeader=h;
	mesh->m_pTexCoords=tex_coords;
	mesh->m_pTriangles=triangles;
	mesh->m_pSkins=skin_name;

	return mesh;
error:
	WARN("Can't Alloc Memory For SMD2Mesh");
	if(mesh!=NULL)
	{
		free(mesh);
	}
	if(frames!=NULL)
	{
		for(i=0;i<h->m_iNumVertices;i++)
		{
			SMD2Frame_Destory(frames+i);
		}
		free(frames);
	}
	if(triangles!=NULL)
	{
		free(triangles);
	}
	if(tex_coords!=NULL)
	{
		free(tex_coords);
	}
	if(skin_name!=NULL)
	{
		for(i=0;i<h->m_iNumSkins;i++)
		{
			if(skin_name[i]!=NULL)
			{
				free(skin_name[i]);
			}
		}
		free(skin_name);
	}

	return NULL;
}

/* from md2 file load frame information */
static int s_mesh_load_frame(struct SMD2Mesh* mesh,FILE* file)
{
	
	struct SMD2Header* header=mesh->m_pHeader;
	struct SMD2Frame* frame=mesh->m_pFrames;
	assert(frame);
	assert(header);
	int i,j;
	size_t readnu;

	fseek(file,header->m_iOffsetFrames,SEEK_SET);
	char* frame_buf=(char*)malloc(header->m_iFrameSize);
	char* p_verts=NULL;
	int vert_offset=sizeof(struct SMD2Frame)-sizeof(struct SMD2Vert*);
	if(frame==NULL)
	{
		WARN("Can't Alloc Memory For SMD2Mesh");
		return -1;
	}
	for(i=0;i<header->m_iNumFrames;i++)
	{
		frame=mesh->m_pFrames+i;
		readnu=fread(frame_buf,header->m_iFrameSize,1,file);
		if(readnu!=1)
		{
			free(frame_buf);
			WARN("Load Data Failed");
			return -1;
		}
		memcpy(frame,frame_buf,vert_offset);

		p_verts=frame_buf+vert_offset;
		assert(frame->m_pVerts);
		for(j=0;j<header->m_iNumVertices;j++)
		{
			frame->m_pVerts[j].m_fX=(*p_verts++)*frame->m_fScale[0]+frame->m_fTrans[0];
			frame->m_pVerts[j].m_fY=(*p_verts++)*frame->m_fScale[1]+frame->m_fTrans[1];
			frame->m_pVerts[j].m_fZ=(*p_verts++)*frame->m_fScale[2]+frame->m_fTrans[2];
		}


	}
	free(frame_buf);
	return 0;

}

/* from md2 file load Triangles index and texture Coords index */
static int s_mesh_load_triangles(struct SMD2Mesh* mesh,FILE* file)
{

	int readnu;
	struct SMD2Header* header=mesh->m_pHeader;
	assert(header);
	assert(mesh->m_pTriangles);
	/* Load Triangles */
	fseek(file,header->m_iOffsetTriangles,SEEK_SET);
	readnu=fread(mesh->m_pTriangles,sizeof(struct SMD2Tri),header->m_iNumTriangle,file);
	if(readnu<header->m_iNumTriangle)
	{
		WARN("Load Triangles Failed");
		return -1;
	}
	return 0;
}

static int s_mesh_load_skin(struct SMD2Mesh* mesh,FILE* file)
{
	assert(mesh->m_pHeader);
	assert(mesh->m_pSkins);
	int i,readnu;
	fseek(file,mesh->m_pHeader->m_iOffsetSkins,SEEK_SET);
	for(i=0;i<mesh->m_pHeader->m_iNumSkins;i++)
	{
		assert(mesh->m_pSkins[i]);
		readnu=fread(mesh->m_pSkins[i],SMD2_SKIN_NAME_LENGTH,1,file);
		if(readnu!=1)
		{
			WARN("Load Skin Failed");
			return  -1;
		}
	}
	return 0;
}
struct smd2_tex_coord
{
	short x;
	short y;
};

/* from md2 file load Texture coords */
static int s_mesh_load_texcoord(struct SMD2Mesh* mesh,FILE* file)
{
	int readnu,i;
	int texnu=mesh->m_pHeader->m_iNumTexCoords;
	struct smd2_tex_coord* texs=(struct smd2_tex_coord*)malloc(sizeof(*texs)*texnu);
	if(texs==NULL)
	{
		WARN("Can't Alloc Memory For Loading TexCoords");
		return -1;
	}
	fseek(file,mesh->m_pHeader->m_iOffsetTexCoords,SEEK_SET);
	readnu=fread(texs,sizeof(*texs),texnu,file);

	if(readnu<texnu)
	{
		free(texs);
		WARN("Load TexCoords Failed(%d,%d)",readnu,texnu);
		return -1;
	}
	int tex_width=mesh->m_pHeader->m_iSkinWidthPx;
	int tex_height=mesh->m_pHeader->m_iSkinHeightPx;

	for(i=0;i<texnu;i++)
	{
		mesh->m_pTexCoords[i].m_fX=texs[i].x/(float) tex_width;
		mesh->m_pTexCoords[i].m_fY=texs[i].y/(float) tex_height;
	}
	free(texs);
	return 0;
}

		

struct SMD2Mesh* SMD2Mesh_Create(FILE* file)
{
	int ret;
	struct SMD2Header* header=SMD2_LoadHeader(file);
	if(header==NULL)
	{
		return NULL;
	}

	struct SMD2Mesh* mesh=s_smd2mesh_alloc(header);
	if(mesh==NULL)
	{
		free(header);
		return NULL;
	}

	ret=s_mesh_load_frame(mesh,file);
	if(ret<0)
	{
		goto error;
	}
	ret=s_mesh_load_triangles(mesh,file);
	if(ret<0)
	{
		goto error;
	}
	ret=s_mesh_load_skin(mesh,file);
	if(ret<0)
	{
		goto error;
	}
	ret=s_mesh_load_texcoord(mesh,file);
	if(ret<0)
	{
		goto error;
	}
	return mesh;

error:
	return NULL;
}
void SMD2Mesh_Destory(struct SMD2Mesh* sm)
{
	int i;

	if(sm->m_pFrames)
	{
		for(i=0;i<sm->m_pHeader->m_iNumFrames;i++)
		{
			if(sm->m_pFrames[i].m_pVerts)
			{
				free(sm->m_pFrames[i].m_pVerts);
			}
		}
		free(sm->m_pFrames);
	}
	if(sm->m_pSkins!=NULL)
	{
		for(i=0;i<sm->m_pHeader->m_iNumSkins;i++)
		{
			if(sm->m_pSkins[i]!=NULL)
			{
				free(sm->m_pSkins[i]);
			}
		}
		free(sm->m_pSkins);
	}
	if(sm->m_pTexCoords)
	{
		free(sm->m_pTexCoords);
	}
	if(sm->m_pTriangles)
	{
		free(sm->m_pTriangles);
	}
	if(sm->m_pHeader)
	{
		free(sm->m_pHeader);
	}
	free(sm);
}

void SMD2Frame_Destory(struct SMD2Frame* sf)
{
	if(sf->m_pVerts)
	{
		free(sf->m_pVerts);
	}
	free(sf);
}


	

static char* s_header_name[]=
{
	"MagicNumber",
	"Version",
	"SKinWidthPx",
	"SkinHeightPx",
	"FrameSize",
	"NumSkin",
	"NumVertices",
	"NumTexCoords",
	"NumTriangle",
	"NumGlCommands",
	"NumFrames",
	"OffsetSkin",
	"OffsetTexCoords",
	"OffsetTriangles",
	"OffsetFrames",
	"OffsetGlCommand",
	"FillSize",
};

static void s_print_indent(int value)
{
	int i;
	for(i=0;i<value;i++)
	{
		printf("\t");
	}
}
static void s_smd2header_print(struct SMD2Header* h,int indent)
{
	int i;
	s_print_indent(indent);
	printf("MD2Header{\n");
	s_print_indent(indent+1);
	printf("%s:%d (IDP2)\n",s_header_name[0],h->m_iMagicNum);
	for(i=1;i<17;i++)
	{
		s_print_indent(indent+1);
		printf("%s:%d\n",s_header_name[i],*((int*)h+i));
	}
	s_print_indent(indent);
	printf("}\n");
}



void SMD2Header_Print(struct SMD2Header* h)
{
	s_smd2header_print(h,0);
}

static void s_smd2frame_print(struct SMD2Frame* f,int nuverts,int indent)
{
	int i;
	s_print_indent(indent);
	printf("MD2Frame{\n");
	s_print_indent(indent+1);
	printf("Name:%s\n",f->m_cName);

	s_print_indent(indent+1);
	printf("Scale:%f %f %f\n",f->m_fScale[0],f->m_fScale[1],f->m_fScale[2]);
	s_print_indent(indent+1);
	printf("Translate:%f %f %f\n",f->m_fTrans[0],f->m_fTrans[1],f->m_fTrans[2]);

	s_print_indent(indent+1);
	printf("Vertex{\n");
	for(i=0;i<nuverts;i++)
	{
		s_print_indent(indent+2);
		printf("%f,%f,%f\n",f->m_pVerts[i].m_fX,f->m_pVerts[i].m_fY,f->m_pVerts[i].m_fZ);
	}
	s_print_indent(indent+1);
	printf("}\n");
	s_print_indent(indent);
	printf("}\n");
}

static void s_smd2mesh_print_skin(struct SMD2Mesh* mesh,int indent)
{
	int i;
	s_print_indent(indent);
	printf("Skin{\n");
	for(i=0;i<mesh->m_pHeader->m_iNumSkins;i++)
	{
		s_print_indent(indent+1);
		printf("%s\n",mesh->m_pSkins[i]);
	}

	s_print_indent(indent);
	printf("}\n");
}
static void s_smd2mesh_print_triangle(struct SMD2Mesh* mesh,int indent)
{
	int i;
	s_print_indent(indent);
	printf("TrianglesAndTextureIndex{\n");
	for(i=0;i<mesh->m_pHeader->m_iNumTriangle;i++)
	{
		s_print_indent(indent+1);
		printf("%d %d %d,",mesh->m_pTriangles[i].m_sVertIndices[0],mesh->m_pTriangles[i].m_sVertIndices[1],mesh->m_pTriangles[i].m_sVertIndices[2]);
		printf("%d %d %d\n",mesh->m_pTriangles[i].m_sTexIndices[0],mesh->m_pTriangles[i].m_sTexIndices[1],mesh->m_pTriangles[i].m_sTexIndices[2]);
	}

	s_print_indent(indent);
	printf("}\n");
}
static void s_smd2mesh_print_texcoord(struct SMD2Mesh* mesh,int indent)
{
	int i;
	s_print_indent(indent);
	printf("TexCoords{\n");
	for(i=0;i<mesh->m_pHeader->m_iNumTexCoords;i++)
	{
		s_print_indent(indent+1);
		printf("%f %f\n",mesh->m_pTexCoords[i].m_fX,mesh->m_pTexCoords[i].m_fY);
	}
	s_print_indent(indent);
	printf("}\n");
}
		


void SMD2Mesh_Print(struct SMD2Mesh* mesh)
{
	printf("SMD2Mesh{\n");
	s_smd2header_print(mesh->m_pHeader,1);
	s_smd2mesh_print_skin(mesh,1);
	s_smd2mesh_print_triangle(mesh,1);
	s_smd2mesh_print_texcoord(mesh,1);
	int i;
	for(i=0;i<mesh->m_pHeader->m_iNumFrames;i++)
	{
		s_smd2frame_print(mesh->m_pFrames+i,mesh->m_pHeader->m_iNumVertices,1);
	}
	printf("}\n");
}







	



