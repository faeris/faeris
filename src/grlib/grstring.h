#ifndef GRLIB_GR_STRING_H_
#define GRLIB_GR_STRING_H_
#include"grobject.h"
#include<string>
class GrString:public GrObject
{
	private:
		std::string m_string;
		size_t m_hash_code;

	public: 
		GrString();
		inline GrString(const char* str);

	public:
		virtual size_t getHashCode()const ;
		virtual const char* getName()const;
		inline GrString& append(const char* str);
		inline GrString& append(const char* str,size_t n);
		inline GrString& append(const GrString& str);
		inline GrString& append(const GrString& str,size_t n);

		inline GrString& assign(const GrString& str);
		inline GrString& assign(const GrString& str,size_t n);
		inline GrString& assign(const char* str);
		inline GrString& assign(const char* str,size_t n);

		inline void clear();
		inline int compare(const GrString& str) const;
		inline int compare(const char* str)const;
		inline const char* c_str()const;
		inline bool empty()const; 
		inline size_t length()const;
		inline GrString& erase(size_t pos,size_t num=1);
		inline char operator[](size_t n)const ;
	private:
		inline void mCalHashCode();
};
#include"grstring.inl"
#endif 
	





	
