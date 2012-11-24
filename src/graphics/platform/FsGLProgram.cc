#include "graphics/FsProgram.h"
#include "GL/glew.h"
#define FS_MAX_GL_PROGRAM_LOG_LENGTH 1024
FAERIS_NAMESPACE_BEGIN
Program* Program::create(Shader* vertex,Shader* fragment)
{
	GLuint program;
	FsChar* log_info=NULL;
	FsInt log_length;
	GLint link_result;

	program=glCreateProgram();
	if(vertex)
	{
		glAttachShader(program,vertex->getPlatformShader());
	}
	if(fragment)
	{
		glAttachShader(program,fragment->getPlatformShader());
	}
	glLinkProgram(program);
	glGetProgramiv(program,GL_LINK_STATUS,&link_result);
	if(link_result==GL_FALSE)
	{
		log_info=new FsChar[FS_MAX_GL_PROGRAM_LOG_LENGTH];
		glGetProgramInfoLog(program,FS_MAX_GL_PROGRAM_LOG_LENGTH,&log_length,log_info);
		log_info[FS_MAX_GL_PROGRAM_LOG_LENGTH-1]='\0';
		FS_TRACE_WARN("Program Result(%s)",log_info);
		delete[] log_info;
		glDeleteProgram(program);
		return NULL;
	}

	Program* ret=new Program(program,vertex,fragment);
	return ret;
}
Program::Program(GLuint program,Shader* vertex,Shader* fragment)
{
	if(vertex)
	{
		vertex->addRef();
	}
	if(fragment)
	{
		fragment->addRef();
	}
	m_vertex=vertex;
	m_fragment=fragment;
	m_program=program;
}
Program::~Program()
{
	if(m_vertex)
	{
		m_vertex->release();
	}
	if(m_fragment)
	{
		m_fragment->release();
	}
	glDeleteProgram(m_program);
}
const FsChar* sProgramName="Program";
const FsChar* Program::getName()
{
	return sProgramName;
}

FAERIS_NAMESPACE_END 

