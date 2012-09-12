#ifndef _FAERY_XIR_SCRIPT_H_
#define _FAERY_XIR_SCRIPT_H_
#define ASCII_NUM 256
struct tagXirState
{
	const char* name;
	unsigned char* input_map;
	bool finally;
	int token;
	struct tagXirState**  targets;

	struct tagXirState* next(char c)
	{
		return targets[input_map[(unsigned char)c]];
	}
	int isFinnally()
	{
		return finally;
	}
};

typedef  struct tagXirState XirState;


#endif  /* _FAERY_XIR_SCRIPT_H_ */


