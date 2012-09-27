#ifndef GRLIB_GR_OBJECT_H_
#define GRLIB_GR_OBJECT_H_
class GrObject 
{
	public:
		enum
		{
			ERR_HASH_CODE=0,
		};
	private:
		int m_refnu;
	public:
		GrObject():m_refnu(1){ }
		void addRef();
		void decRef();
		int refCount();

		virtual const char* getName()const=0; 
		virtual size_t getHashCode()const; 
		virtual int equal(GrObject* g)const;

		virtual ~GrObject();
};
#endif 

