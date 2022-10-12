#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCapacity(SeqList* ps)
{
	assert(ps);
	int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	SLDateType* tmp = (SLDateType*)realloc(ps->a, newCapacity * sizeof(SLDateType));
	if (tmp == NULL)
	{
		perror("realloc fail");
	}
	ps->a = tmp;
	ps->capacity = newCapacity;
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int begin = 0;
	while (begin <= ps->size-1)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}
	--ps->size;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	/*if (ps->size == 0)
	{
		return;
	}*/
	assert(ps->size > 0);

	ps->a[ps->size - 1] = 0;
	--ps->size;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);
	SeqListCapacity(ps);

	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[pos] = x;
	++ps->size;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	size_t begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}
	--ps->size;
}