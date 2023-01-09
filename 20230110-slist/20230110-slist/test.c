#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

int main()
{

	SListNode* a = NULL;
	SListPushBack(&a, 1);
	SListPrint(a);
	SListPushFront(&a, 2);
	SListPushFront(&a, 3);
	SListPrint(a);

	SListPopBack(&a);
	SListPrint(a);

	SListPopFront(&a);
	SListPrint(a);

	SListNode* p = SListFind(a, 2);
	printf("%d\n", p->data);

	SListInsertAfter(p,3);
	SListPrint(a);

	SListEraseAfter(a);
	SListPrint(a);




	return 0;
}