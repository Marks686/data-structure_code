#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;

		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}

			a[end + gap] = tmp;
		}
	}
}


oid Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void BubbleSort(int* a, int n)
{
	assert(a);

	int end = n;
	while (end > 0)
	{
		/*
		加一个标记，如果中间没有发生交换
		说明前面的值都比后面的小
		即本身就是有序的，最好的情况下，
		它的时间复杂度就为N
		*/
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}

		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 三数取中法，三个中取一个中间值

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // begin >= mid
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}

int PartSort1(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int start = begin;
	/*
	这里要从右边走，如果从左边走，
	可能最后一步，如果找不到大于
	基准值的，会导致begin == end
	即相遇，但是右边还没有走，所以
	这里的值一定大于基准值，最后交换
	就会出问题，所以一定要从右边走，
	即使最后一次找不到小于基准值的，
	会和左边相遇，而左边此时还没走，
	一定比基准值小，最后交换肯定没有问题
	*/
	while (begin < end)
	{
		// end 找小
		while (begin < end && a[end] >= key)
			--end;

		// begin找大
		while (begin < end && a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
	//最后的交换一定要保证a[begin] < a[start], 所以要从右边走
	Swap(&a[begin], &a[start]);
	return begin;
}

int PartSort2(int* a, int begin, int end)
{
	//begin是坑
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			--end;

		// end给begin这个坑，end就变成了新的坑。
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
			++begin;

		// end给begin这个坑，begin就变成了新的坑。
		a[end] = a[begin];
	}

	a[begin] = key;

	return begin;
}


/*
前后指针法
*/
int PartSort3(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;

	while (cur <= end)
	{
		// cur找小，把小的往前翻，大的往后翻
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[begin], &a[prev]);

	return prev;
}

// []
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int div = PartSort3(a, left, right);
		//[left, div-1]
		//[div+1, right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
//用栈模拟递归，用队列也可以实现
void QuickSortR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st, 10);
	//先入大区间
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}
	//栈不为空，说明还有没处理的区间
	while (StackEmpty(&st) != 0)
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		//快排单趟排序
		int div = PartSort1(a, left, right);
		// [left div-1]
		// 把大于1个数的区间继续入栈
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}

		// [div+1, right]
		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}

}

void TestQuickSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	QuickSortR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}