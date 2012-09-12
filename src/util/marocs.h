#ifndef MAROC_UTILITY_H_
#define MAROC_UTILITY_H_

#include<stdio.h>


#define Maroc_Func_Condition(name,condition,args...) \
	do{ \
		if(condition)\
		{\
			fprintf(stderr,"%s::%s(Line %d):",__FILE__,__func__,__LINE__);\
			fprintf(stderr,"%s(%s,",#name,#condition);\
			fprintf(stderr,args);\
			fprintf(stderr,")\n");\
		}\
	}while(0)

#define Maroc_Func(name,args...) \
	do{ \
		fprintf(stderr,"%s::%s(Line %d):",__FILE__,__func__,__LINE__);\
		fprintf(stderr,"%s(",#name);\
		fprintf(stderr,args);\
		fprintf(stderr,")\n");\
	}while(0)

#define MAROC_ALL

#ifdef MAROC_ALL
#define MAROC_DEBUG
#define MAROC_WARN
#define MAROC_BUG
#define MAROC_TODO
#define MAROC_FIXME
#define MAROC_INFO
#define MAROC_DEBUG_ON
#define MAROC_WARN_ON
#define MAROC_BUG_ON
#define MAROC_DEBUG_CODES
#endif 

/*INFO*/
#ifdef MAROC_INFO
#define INFO(args...) Maroc_Func(INFO,args)
#else
#define INFO(args...)
#endif 
/*TODO*/
#ifdef MAROC_TODO
#define TODO(args...) Maroc_Func(TODO,args)
#else
#define TODO(args...)
#endif 

/*FIXME*/
#ifdef MAROC_FIXME
#define FIXME(args...) Maroc_Func(FIXME,args)
#else 
#define FIXME(args...)
#endif 

/*DEBUG_ON*/
#ifdef MAROC_DEBUG_ON
#define DEBUG_ON(condition,args...) Maroc_Func_Condition(DEBUG_ON,condition,args)
#else
#define DEBUG_ON(args...) 
#endif

/*WARN_ON*/
#ifdef MAROC_WARN_ON 
#define WARN_ON(condition,args...) Maroc_Func_Condition(WARN_ON,condition,args)
#else
#define WARN_ON(args...)
#endif

/*BUG_ON*/
#ifdef MAROC_BUG_ON
#define BUG_ON(condition,args...) Maroc_Func_Condition(BUG_ON,condition,args)
#else
#define BUG_ON(args...)
#endif 

/*DEBUG*/
#ifdef MAROC_DEBUG
#define DEBUG(args...) Maroc_Func(DEBUG,args)
#else
#define DEBUG(args...) 
#endif

/*WARN*/
#ifdef MAROC_WARN 
#define WARN(args...) Maroc_Func(WARN,args)
#else
#define WARN(args...)
#endif

/*BUG*/
#ifdef MAROC_BUG
#define BUG(args...) Maroc_Func(BUG,args)
#else
#define BUG(args...)
#endif 

#ifdef MAROC_DEBUG_CODES
#define DEBUG_CODES if(1)
#else
#define DEBUG_CODES if(0)
#endif


#endif
