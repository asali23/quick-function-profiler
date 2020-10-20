#define NO_OF_PROFILING_READING 50
#define TICKS_PER_MSEC 2823
#define DEBUG_LEVELS 100

#define PP {\
	int value = 0;\
	int tabs = 0;\
	int val = 0;\
	int acc[DEBUG_LEVELS];\
	while(1)\
	{\
		int result = cb_pop_front(&value);\
		if(result == -1)\
			break;\
		if(tabs == 0)\
		{\
			for(int i=0;i<DEBUG_LEVELS;i++)\
				acc[i] = 0;\
		}\
		if(value == 0)\
		{\
			if(val==1)\
				for(int i=0;i<tabs-1;i++)\
					printf("---");\
			cb_pop_front(&value);\
			acc[tabs] = acc[tabs] + value;\
			printf("%.1f ms (%.1f ms)\n",value/float(TICKS_PER_MSEC),acc[tabs]/float(TICKS_PER_MSEC));\
			val=1;\
			tabs--;\
		}\
		else\
		{\
			if(val == 0)\
				printf("\n");\
			val=0;\
			for(int i=0;i<tabs;i++)\
				printf("---");\
			printf("%s  ",value);\
			tabs++;\
		}\
	}\
}\


#define PS(name) {\
static char fname[] = #name;\
cb_push_back((int)&fname);\
UINT64 tss = NU_Get_Time_Stamp();

#define PE \
	UINT64 tse = NU_Get_Time_Stamp();\
	cb_push_back(0);\
	cb_push_back((int)(tse-tss));\
}

#define PI \
	cb_init(NO_OF_PROFILING_READING*2);
