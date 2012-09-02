#include<util/util.h>
#include<assert.h>
inline GrString::GrString():m_string("")
{
	mCalHashCode();
}
inline GrString::GrString(const char* str):m_string(str)
{
	mCalHashCode();
}
inline GrString& GrString::append(const char* str)
{
	m_string.append(str);
	mCalHashCode();
	return *this;
}
inline GrString& GrString::append(const char* str,size_t n)
{
	m_string.append(str,n);
	mCalHashCode();
	return *this;
}
inline GrString& GrString::append(const GrString& str)
{
	m_string.append(str.m_string);
	mCalHashCode();
	return *this;
}
inline GrString& GrString::append(const GrString& str,size_t n)
{
	m_string.append(str.m_string,0,n);
	mCalHashCode();
	return *this;
}

inline GrString& GrString::assign(const GrString& str)
{
	m_string.assign(str.m_string);
	m_hash_code=str.m_hash_code;
	return *this;
}
inline GrString& GrString::assign(const GrString& str,size_t n)
{
	m_string.assign(str.m_string,0,n);
	mCalHashCode();
	return *this;
}
inline GrString& GrString::assign(const char* str)
{
	m_string.assign(str);
	mCalHashCode();
	return *this;
}
inline GrString& GrString::assign(const char* str,size_t n)
{
	m_string.assign(str,n);
	mCalHashCode();
	return *this;
}
inline void GrString::clear()
{
	m_string.clear();
	mCalHashCode();
}
inline int GrString::compare(const GrString& str)const 
{
	return m_string.compare(str.m_string);
}
inline int GrString::compare(const char* str)const
{
	return m_string.compare(str);
}
inline const char* GrString::c_str()const
{
	return m_string.c_str();
}
inline bool GrString::empty()const 
{
	return m_string.empty();
}
inline size_t GrString::length()const 
{
	return m_string.length();
}
inline GrString& GrString::erase(size_t pos,size_t num)
{
	m_string.erase(pos,num);
	return *this;
}
inline void GrString::mCalHashCode()
{
	m_hash_code=Util_JStringHashCode(m_string.c_str());
	if(m_hash_code==ERR_HASH_CODE)
	{
		m_hash_code+=1;
	}
}

inline char GrString::operator[](size_t n)const 
{
	assert(n<length());
	return m_string[n];
}









