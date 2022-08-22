#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void SLInt(SL sl)
{
	sl.a = NULL;
	sl.capacity = sl.size = 0;
}

void SLDestory(SL sl);