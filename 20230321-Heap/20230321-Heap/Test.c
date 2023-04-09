#include "Heap.h"

int main()
{
	//int a[] = { 15, 18, 19, 25, 28, 34, 65, 49, 27, 37 };
	int a[] = { 65, 100, 70, 32, 50, 60 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}

	//HeapPush(&hp, 10);
	HeapPrint(&hp);

	//HeapPop(&hp);
	//HeapPrint(&hp);

	//HeapPop(&hp);
	//HeapPrint(&hp);

	/*while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}*/


	return 0;
}