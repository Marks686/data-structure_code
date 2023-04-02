#include "Sort.h"
#include "Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
}

//void ShellSort(int* a, int n)
//{
//
//	int gap = 3;
//	for(int j = 0; j < gap; j++)
//	{
//		for (int i = j; i < n - gap; i += gap)
//		{
//			//[0,end] 插入 end+gap [0,end+gap]有序 --间隔为gap的数据
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			a[end + gap] = tmp;
//		}
//	}
//}


void ShellSort(int* a, int n)
{
	//gap > 1 预排序
	//gap == 1 直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3) + 1;
		for (int i = 0; i < n - gap; i++)
		{
			//[0,end] 插入 end+gap [0,end+gap]有序 --间隔为gap的数据
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		// 找出小的那个孩子
		if (minChild + 1 < n && a[minChild + 1] > a[minChild])
		{
			minChild++;
		}

		if (a[minChild] > a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


// O(N*logN)
void HeapSort(int* a, int n)
{
	// 大思路：选择排序，依次选数，从后往前排
	// 升序 -- 大堆
	// 降序 -- 小堆
	// 建堆 -- 向下调整建堆 - O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// 选数
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		++i;
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//选出最小的放begin位置
		//选出最大的放end位置
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}



void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] >= a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//单趟排序(Hoare大佬法)
//[left,right]
int PartSort1(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int keyi = left;
	while (left < right)
	{
		//让R先找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//L找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;
	Swap(&a[meeti], &a[keyi]);

	return meeti;
}

//挖坑
int PartSort2(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//右边找小填左边的坑
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;

		//左边找大填右边的坑
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}


//前后指针法
int PartSort3(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);

	return prev;
}

//[left,right]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	if (end-begin <= 8)
	{
		InsertSort(a + begin, end - begin + 1); 
	}
	else
	{
		int keyi = PartSort3(a, begin, end);
		//[begin,keyi-1] keyi [keyi,end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}

//快排的非递归
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

		/*if (left >= right)
		{
			continue;
		}*/

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1,right]

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestroy(&st);
}