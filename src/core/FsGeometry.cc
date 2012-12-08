#include <string.h>
#include "FsGeometry.h"
FAERIS_BEGIN_NAMESPACE

GeometryType GeometryUtil::GetFileType(const FsChar* name)
{
	FsUint length=strlen(name);
	if(length<=4)
	{
		return FS_GEOMETRY_UNKOWN;
	}
	FsChar* ext=name[length-3];
	if((ext[0]=='g'&&ext[1]=='t'&&ext[2]=='y')||(ext[0]=='G'&&ext[1]=='T'&&ext[2]=='Y'))
	{
		return FS_GEOMETRY_GTY;
	}

	return FS_GEOMETRY_UNKOWN;
}

Geometry* GeometryUtil::loadFromMgr(const FsChar* name,GeometryType type)
{
	FsFile* file=VFS::open(name);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For Geometry",name);
		return NULL;
	}

	Geometry* ret=loadGeometry(file,type);
	delete file;
	return ret;
}

Geometry*  GeometryUtil::loadGeometry(FsFile* f,GeometryType type)
{
	if(type==FS_GEOMETRY_UNKOWN)
	{
		type=GetFileType(name);
	}
	Geometry* ret=NULL;
	switch(type)
	{
		case FS_GEOMETRY_GTY:
			ret=loadGTY(file);
			break;
		case FS_GEOMETRY_UNKOWN:
			FS_TRACE_WARN("Unkown File Type For Geometry");
			break;
	}
	return ret;
}


#define FS_GTY_MAGIC_STRING "GTY3DFT"
#define FS_GTY_VERSTION  (0x1)
#define FS_GTY_HEADER_SIZE (sizeof(GTYHeader))

class GTYHeader
{
	public:
		FsUchar magic[8];  /* magic always "GTY3DFT" */
		FsUint32 version;  /* current is 1.0 */
		FsUint32 vertexNu;
		FsUint32 vertexOffset;
		FsUint32 normalsNu;
		FsUint32 normalsOffset;
		FsUint32 colorsNu;
		FsUint32 colorOffset;
		FsUint32 texCoordsNu;
		FsUint32 texCoordsOffset;
		FsUint32 facesNu;
		FsUint32 facesOffset;
};

Geometry* GeometryUtil::loadGTY(FsFile* f)
{
	GTYHeader gty_header;
	FsInt readbyte;
	FsInt buf_length=0;
	Geometry* g=NULL;
	readbyte=file->read(&gty_header,FS_GTY_HEADER_SIZE);
	if(readbyte<FS_GTY_HEADER_SIZE)
	{
		FS_TRACE_WARN("Error GTY Format:Header Length Is Short Than Standard");
		goto error;
	}
	if(strcmp(gty_header.magic,FS_GTY_MAGIC_STRING)!=0)
	{
		FS_TRACE_WARN("File Is Not GTY Format");
		goto error;
	}
	if(gty_header.version!=1)
	{
		FS_TRACE_WARN("Now Only Support Load GTY File Version 1.0");
		goto error;
	}

	/* create Geometry */
	g=new Geometry;

	/* read vertex */
	if(gty_header.vertexNu>0)
	{
		g->setVertexNu(gty_header.vertexNu);
		file->seek(gty_header.vertexOffset,VFS::FS_SEEK_SET);
		buf_length=sizeof(Vector3)*gty_header.vertexNu;
		readbyte=file->read(&(g->vertices[0]),buf_length);
		if(readbyte<buf_length)
		{
			FS_TRACE_WARN("Error GTY Format:Vertex Buffer Is Short Than Expect(%d,%d)",readbyte,buf_length);
			goto error;
		}
	}

	/* read normals */
	if(gty_header.normalsNu>0)
	{
		g->setNormalsNu(gty_header.normalsNu);
		file->seek(gty_header.normalsOffset,VFS::FS_SEEK_SET);
		buf_length=sizeof(Vector3)*gty_header.normalsNu;
		readbyte=file->read(&(g->normalsNu[0]),buf_length);
		if(readbyte<buf_length)
		{
			FS_TRACE_WARN("Error GTY Format:Normal Buffer Is Short Than Expect(%d,%d)",readbyte,buf_length);
			goto error;
		}
	}

	/* read colors */
	if(gty_header.colorsNu>0)
	{
		g->setColorsNu(gty_header.colorsNu);
		file->seek(gty_header.colorOffset,VFS::FS_SEEK_SET);
		buf_length=sizeof(Color)*gty_header.colorsNu;
		readbyte=file->read(&(g->colorsNu[0]),buf_length);
		if(readbyte<buf_length)
		{
			FS_TRACE_WARN("Error GTY Format:Color Buffer is Short Than Expect(%d,%d)",readbyte,buf_length);
			goto error;
		}
	}

	/* read texcoords */
	if(gty_header.texCoordsNu>0)
	{
		g->setTexCoordsNu(gty_header.texCoordsNu);
		file->seek(gty_header.texCoordsOffset,VFS::FS_SEEK_SET);
		buf_length=sizeof(TexCoord2)*gty_header.texCoordsOffset;
		readbyte=file->read(&(g->texCoords[0]),buf_length);
		if(readbyte<buf_length)
		{
			FS_TRACE_WARN("Error GTY Format:TexCoord Buffer is Short Than Expect(%d,%d)",readbyte,buf_length);
			goto error;
		}
	}

	/* read face */
	if(gty_header.faces>0)
	{
		g->setFacesNu(gty_header.facesNu);
		file->seek(gty_header.facesOffset,VFS::FS_SEEK_SET);
		buf_length=sizeof(Face3)*gty_header.facesNu;
		readbyte=file->read(&(g->faces[0]),buf_length);
		if(readbyte<buf_length)
		{
			FS_TRACE_WARN("Error GTY Format:Face Buffer is Short Than Expect(%d,%d)",readbyte,buf_length);
			goto error;
		}
	}
	return g;
error:
	if(g)
	{
		g->release();
	}
	return NULL;
}

FAERIS_END_NAMESPACE 






















