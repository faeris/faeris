#ifndef FAERIS_OBJECT_H_
#define FAERIS_OBJECT_H_

#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN

class FsObject 
{
	private:
		FsInt m_refNu;
	public:
		void addRef(){m_refNu++;}
		void release()
		{
			m_refNu--;
			FS_TRACE_ERROR_ON(m_refNu<0,"%s Reference Error",getName());
			if(m_refNu<=0)
			{
				onDestory();
			}
		}

	public:
		FsObject():m_refNu(1){}
		virtual ~FsObject();
		virtual const FsChar* getName()=0;
		virtual void onDestory();
};

FAERIS_NAMESPACE_END
#endif 

