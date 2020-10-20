// testr.cpp : Defines the entry point for the console application.
//

#ifdef WIN32


#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "circbuffer.h"

using namespace std;
#define UINT64 __int64
UINT64 NU_Get_Time_Stamp()
{
    LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
    return li.QuadPart;
}
#endif

#include "profiler.h"

int Level3Func1(int a)
{
	Sleep(a*1000);
	return 0;
}
int Level4Func1(int a)
{
	Sleep(a*1000);
	return 0;
}
int Level3Func2(int a)
{
	PS(Level4Func1) Level4Func1(a);PE
	PS(Level4Func1) Level4Func1(a);PE
	return 0;
}

int HelperFunc(int a)
{
	PS(Level3Func1) Level3Func1(a);  PE
	PS(Level3Func2) Level3Func2(a);  PE
	PS(Sleep) Sleep(a*1000); PE
	return 0;
}

int myfunc(int a)
{
	PS(Sleep) Sleep(a*1000); PE
	PS(HelperFunc) HelperFunc(a); PE
	return 0;
}


int main(int argc, char* argv[])
{
	PI
	PS(myfunc)  myfunc(1);PE
	PP

#if 0
	int value = 0;
	int tabs = 0;
	int acc[10];
	while(1)
	{
		int result = cb_pop_front(&value);
		if(result == -1)
			break;
		if(tabs == 0)
		{
			for(int i=0;i<10;i++)
				acc[i] = 0;
		}
		if(value == 0)// Next value is time
		{
			for(int i=0;i<tabs-1;i++)
				printf("---");
			cb_pop_front(&value);
			acc[tabs] = acc[tabs] + value;
			printf("%.1f (%.1f)\n",value/28800.0,acc[tabs]/28800.0);
			tabs--;
		}
		else
		{
			for(int i=0;i<tabs;i++)
				printf("---");
			printf("%s\n",value);
			//acc[tabs] = 0;
			tabs++;
			//acc[tabs] = 0;
			
		}

	}
#endif	
	return 0;
}


