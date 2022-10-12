#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"



//int** fun(int n)
//{
//    int** s = (int**)malloc(n * sizeof(int*));
//    while (n--)
//    {
//        s[n] = (int*)malloc(n * sizeof(int));
//
//    }
//    return s;
//}
//int main()
//{
//
//	return 0;
//}
int test1()
{
	SeqList s;

	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -4);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListDestroy(&s);
}

int test2()
{
	SeqList s;

	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);



	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);
	SeqListDestroy(&s);

}
int test3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -4);
	SeqListPrint(&s);

	int k = SeqListFind(&s, -4);
	printf("你想找的数的下标是：%d\n", k);

	SeqListInsert(&s,0,100);
	SeqListPrint(&s);

	SeqListDestroy(&s);

}
int test4()
{

}
int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}
