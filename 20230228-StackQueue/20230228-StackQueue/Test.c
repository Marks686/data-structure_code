
//int f(int n)
//{
//	return n == 1 ? 1 : f(n - 1) + n;
//}
//int main()
//{
//	printf("%d\n",f(100));
//	return 0;
//}

#include "Stack.h"

void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
}

int main()
{
	TestStack();

	return 0;
}