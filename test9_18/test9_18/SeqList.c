#define _CRT_SECURE_NO_WARNINGS

#include  "SeqList.h"
void SLInit(SL* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->size = psl->capacity = 0;
}

void SLPrint(const SL* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
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
		SLDataType* tmp = realloc(psl->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}

void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);

	SLCheckCapacity(psl);

	int end = psl->size;
	psl->a[end] = x;
	psl->size++;
}

void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);

	SLCheckCapacity(psl);

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

	if (psl->size == 0)
	{
		return;
	}

	psl->size--;
}

void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);

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
