#include "SeqList.h"


void SLInit(SL* psl)
{
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}

void SLDestory(SL sl);
