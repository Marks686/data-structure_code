#define _CRT_SECURE_NO_WARNINGS

#include  "SeqList.h"


void TestSeqList1()
{
	SL s;
	SLInit(&s); 
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPushFront(&s, 30);
	SLPushFront(&s, 300);
	SLPushBack(&s, 400);
	SLPrint(&s);

	SLPopBack(&s); 
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLDestory(&s);
}

void TestSeqList2()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	int x = 0;
	scanf("%d", &x);
	SLFind(&s, x);
	int ret = SLFind(&s, x);
	printf("%d\n", ret);
	
}

int main()
{

	TestSeqList2();
	return 0;

}