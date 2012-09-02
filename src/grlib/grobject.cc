#include"grobject.h" 
GrObject::~GrObject(){}
const char* GrObject::getName()const
{
	return "GrObject";
}
size_t GrObject::getHashCode()const 
{
	return ERR_HASH_CODE;
}
