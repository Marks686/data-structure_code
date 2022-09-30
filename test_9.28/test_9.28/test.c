#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	printf("\n");
}


void TestSList2()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);


}

void TestSList3()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		//修改
		pos->data *= 10;
		printf("找到了\n");

	}
	else
	{
		printf("没有找到\n");
	}
	

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
	}
	SListPrint(plist);


	SListDestory(&plist);
}
int main()
{
	//TestSList1();
	//TestSList2();
	TestSList3();
	return 0;
}