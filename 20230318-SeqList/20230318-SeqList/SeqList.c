#include "SeqList.h"

void SLPrint(const SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->a[i]);

	}
	printf("\n");

}

void SLInit(SL* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->capacity = psl->size = 0;
}

void SLDestory(SL* psl)
{
	assert(psl);

	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;

	
}

void SLCheckCapacity(SL* psl)
{
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}

void SLPushBack(SL* psl, SLDataType x)
{
	SLInsert(psl, psl->size, x);
}

void SLPushFront(SL* psl, SLDataType x)
{
	SLInit(psl, 0, x);
}

void SLPopBack(SL* psl)
{
	SLErase(psl, psl->size - 1);

}

void SLPopFront(SL* psl)
{
	SLErase(psl, 0);
}

int SLFind(SL* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;

		}
	}
	return -1;
}



void SLInsert(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos <= psl->size);

	SLCheckCapacity(psl);
	size_t end = psl->size;
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}

	psl->a[pos] = x;
	++psl->size;
}

void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);

	size_t begin = pos;
	while (begin < psl->size - 1)
	{
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}

	psl->size--;
}