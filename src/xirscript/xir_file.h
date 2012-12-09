#ifndef _FAERY_XIR_SCRIPT_FILE_H_
#define _FAERY_XIR_SCRIPT_FILE_H_ 
#include "fsys/FsFile.h"
class XirFile
{
	private:
		Faeris::FsFile* m_file;
		char* m_buf;
		int m_buf_cap;
		int m_buf_size;
		int m_begin;
		int m_mark;
		int m_buf_pos;
	public:
		XirFile(Faeris::FsFile* file);
		~XirFile();
	protected:
		int loadData();

	public:
		char nextChar();
		void mark()
		{
			m_mark=m_buf_pos;
		}
		void backToMark()
		{
			m_buf_pos=m_mark;
		}
		void ForwardToMark()
		{
			m_begin=m_mark;
			m_buf_pos=m_mark;
		}
};
#endif  /* _FAERY_XIR_SCRIPT_FILE_H_ */


