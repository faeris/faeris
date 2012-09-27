#ifndef GRLIB_GR_DICT_H_
#define GRLIB_GR_DICT_H_
#include<hash_map>
#include"grlib/grobject.h"

class GrObject_Hash
{
	public:
		size_t operator()(const GrObject* g)
		{
			return g->hashCode();
		}
};
class GrObject_Equal
{
	public:
		int operator()(const GrObject* left,const GrObject* right)
		{
			if(left->getName()!=right->getName())
			{
				return false;
			}
			int ret=left->equal(right);
			return ret;
		}
};

class GrDict:public GrObject 
{

};
#endif 


