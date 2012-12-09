#include "graphics/FsShader.h"
#include "GL/glew.h"
#define FS_MAX_GL_SHADER_LOG_LENGTH 1024

FAERIS_NAMESPACE_BEGIN 
Shader* Shader::create(FsFile* file,ShaderType t)
{
	FsInt length,readbyte;
	FsChar* source=NULL;
	FsChar* log_info=NULL;
	Shader* ret=NULL;
	GLint compile_result,log_length;


	GLenum gl_type=t==FS_VERTEX_SHADER?GL_VERTEX_SHADER:GL_FRAGMENT_SHADER;
	GLuint shader=0;
	file->seek(0,FsFile::FS_SEEK_END);
	length=file->tell();
	file->seek(0,FsFile::FS_SEEK_SET);

	source=new FsChar[length];
	readbyte=file->read(source,length);
	if(readbyte<length)
	{
		FS_TRACE_WARN("Expected %d Bytes Data,But Only %d Bytes Read",length,readbyte);
		delete[] source;
		return NULL;
	}

	shader=glCreateShader(gl_type);
	const FsChar* all_source[]={source};
	const FsInt all_source_length[]={length};

	glShaderSource(shader,1,all_source,all_source_length);
	glCompileShader(shader);
	glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_result);

	if(compile_result==GL_FALSE)
	{
		log_info= new FsChar[FS_MAX_GL_SHADER_LOG_LENGTH];
		glGetShaderInfoLog(shader,FS_MAX_GL_SHADER_LOG_LENGTH,&log_length,log_info);
		log_info[FS_MAX_GL_SHADER_LOG_LENGTH-1]='\0';
		FS_TRACE_WARN("Compile Shader(%s)",log_info);
		delete[] log_info;
		goto error;
	}

	if(source)
	{
		delete[] source;
		source=NULL;
	}
	ret=new Shader;
	ret->m_shader=shader;
	return ret;


error:
	if(source)
	{
		delete[] source;
	}
	glDeleteShader(shader);
	return NULL;
}

Shader::~Shader()
{
	glDeleteShader(m_shader);
}
static const FsChar* sShaderName="Shader";
const FsChar* Shader::getName()
{
	return sShaderName;
}

FAERIS_NAMESPACE_END 
