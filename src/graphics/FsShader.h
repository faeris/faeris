#ifndef FAERIS_SHADER_H_
#define FAERIS_SHADER_H_

#include "FsMacros.h"
#include "fsys/FsFile.h"
#include "FsConfig.h"
#include "core/FsObject.h"
#if FS_CONFIG(FS_GL_RENDER)
	typedef FsUint PlatformShader;
#else 
	#error "Unsupport PlatformShader"
#endif 

FAERIS_NAMESPACE_BEGIN
class Shader:public FsObject
{
	public:
		enum ShaderType
		{
			FS_VERTEX_SHADER,
			FS_FRAGMENT_SHADER,
		};
	public:
		static Shader* create(FsFile* file,ShaderType t);
	public:
		PlatformShader getPlatformShader()const{return m_shader;}
		virtual const FsChar* getName();
	protected:
		~Shader();

	private:
		PlatformShader m_shader;
};

FAERIS_NAMESPACE_END

#endif /*FAERIS_SHADER_H_*/
