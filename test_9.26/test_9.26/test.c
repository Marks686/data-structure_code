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
} 
int main()
{
	TestSList1();
	return 0;
}