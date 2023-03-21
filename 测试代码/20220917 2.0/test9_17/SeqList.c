#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void SLPrint(const SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
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

	//if (psl->a)
	//{
		free(psl->a);
		psl->a = NULL;
		psl->capacity = psl->size = 0;
	//}
}

void SLCheckCapacity(SL* psl)
{
	//检查容量
	if (psl->size == psl->capacity)
	{
		int newCapcity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = realloc(psl->a, newCapcity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
			//exit(-1);
		}

		psl->a = tmp;
		psl->capacity = newCapcity;
	}
}

void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);

	SLCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;
}

void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);

	SLCheckCapacity(psl);

	//挪动数据
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[0] = x;
	psl->size++;
}


void SLPopBack(SL* psl)
{
	assert(psl);

	//温柔的检查
	if (psl->size == 0)
	{
		return;
	}

	//暴力的检查
	//assert(psl->size > 0);

	psl->size--;
}

void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);


	//int begin = 0;
	//while (begin < psl->size - 1)
	//{
	//	psl->a[begin] = psl->a[begin + 1];
	//	++begin;
	//}

	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}

	--psl->size;
}

int SLFind(SL* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
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

	//挪动数据
	//int end = psl->size - 1;
	//while (end >= (int)pos)
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	--end; 
	//}

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


void SLModify(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos < psl->size);

	psl->a[pos] = x;
}
