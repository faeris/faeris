#include"xirscript/xir_file.h"
#include"FsMacros.h"
#include<string.h>
#include<stdio.h>
#define LEX_FILE_DEFAULT_SIZE 64
XirFile::XirFile(IFile* f)
{
	m_file=f;
	m_buf= new char[LEX_FILE_DEFAULT_SIZE];
	m_buf_cap=LEX_FILE_DEFAULT_SIZE;
	m_buf_size=0;
	m_begin=0;
	m_mark=0;
	m_buf_pos=0;
}
XirFile::~XirFile()
{
	if(m_buf)
	{
		delete[] m_buf;
		m_buf=0;
	}
}
char XirFile::nextChar()
{
	if(m_buf_pos>=m_buf_size)
	{
		if(loadData()==0)
		{
			return EOF;
		}
	}
	return m_buf[m_buf_pos++];
}

int XirFile::loadData()
{
	//DEBUG("loadData");
	int readbyte;
	if(m_buf_size==0)
	{
		readbyte=m_file->read(m_buf,LEX_FILE_DEFAULT_SIZE);
		m_buf_size=readbyte;
		return readbyte;
	}

	int begin=m_begin;
	int mark=m_mark;
	int read_pos=m_buf_pos;
	int buf_cap=m_buf_cap;

	int buf_used=m_buf_size-begin;
	int buf_free=buf_cap-buf_used;

	if(buf_free<LEX_FILE_DEFAULT_SIZE/2)
	{

		char* new_buf=new char[buf_cap*2];
		memcpy(new_buf,m_buf+begin,buf_used);
		delete[] m_buf;
		m_buf=new_buf;
		m_buf_cap=m_buf_cap*2;
	}
	else
	{
		int i;
		char* buf=m_buf;
		for(i=0;i<buf_used;i++)
		{
			buf[i]=buf[i+begin];
		}
	}

	m_begin=0;
	m_mark=mark-begin;
	m_buf_pos=read_pos-begin;

	readbyte=m_file->read(m_buf+buf_used,buf_cap-buf_used);
	m_buf_size=buf_used+readbyte;
	return readbyte;
}





















