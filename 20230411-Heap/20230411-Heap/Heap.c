#include "Heap.h"

void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType* x = *x1;
	*x1 = *x2;
	*x2 = x;
}

void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选左右孩子中大的一个
		if (child + 1 < n && a[child+1] > a[child])
		{
			++child;
		}


		//如果孩子大于父亲，交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent;
	assert(a);
	parent = (child - 1) / 2;
	while (child > 0)
	{
		//如果孩子大于父亲，进行交换
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = n;
	hp->_capacity = n;

	for (int i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}

	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}


void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity);
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);

	Swap(&hp->_a, &hp->_a[hp->_size - 1]);

	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 0 : 1;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	HeapInit(&hp, a, k);

	for (size_t i = k; i < n; ++i)
	{
		if (a[i] < HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}