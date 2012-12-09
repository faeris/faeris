#ifndef FAERIS_PROGRAM_H_
#define FAERIS_PROGRAM_H_

#include "FsMacros.h"
#include "fsys/FsFile.h"
#include "FsConfig.h"
#include "core/FsObject.h"
#include "graphics/FsShader.h"
#if FS_CONFIG(FS_GL_RENDER)
	typedef FsUint PlatformProgram;
#else 
	#error "Unsupport PlatformProgram"
#endif 

FAERIS_NAMESPACE_BEGIN 
class Program:public FsObject
{
	public:
		static Program* create(Shader* vertex,Shader* fragment);
	public:
		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const FsChar* getName();
	protected:
		Program(PlatformProgram p,Shader* vertec,Shader* fragment);
		~Program();
	private:
		PlatformProgram m_program;
		Shader* m_vertex;
		Shader* m_fragment;
};
FAERIS_NAMESPACE_END 

#endif  /*FAERIS_PROGRAM_H_*/

