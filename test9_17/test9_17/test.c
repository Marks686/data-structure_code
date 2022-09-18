#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);



	SLPushBack(&s, 10);
	SLPushBack(&s, 20);
	SLPushBack(&s, 30);
	SLPushBack(&s, 40);
	SLPrint(&s);


	SLDestory(&s);
}


void TestSeqList3()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);


	SLPopFront(&s);
	SLPopFront(&s);

	SLPrint(&s);

	int* p1 = (int*)malloc(sizeof(int) * 10);
	assert(p1);
	printf("p1:%p\n", p1);

	int* p2 = (int*)realloc(p1,sizeof(int) * 20);
	assert(p2);
	printf("p2:%p\n", p2);

}


void TestSeqList4()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	//SLInsert(&s, 2, 30);
	SLInsert(&s, 0, 30);

	SLPrint(&s);

	int x = 0;
	scanf("%d", &x);

	int pos = SLFind(&s, x);
	if (pos != -1)
	{
		SLInsert(&s, pos, 3*100);
	}
	SLPrint(&s);

}


void TestSeqList5()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLErase(&s, 0);
	SLPrint(&s);


	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&s, x);
	if (pos != -1)
	{
		SLErase(&s, pos);
	}
	SLPrint(&s);

}
int main()
{
	TestSeqList5();
	return 0;
}