#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//打印
void PrintArray(int* a, int n);

//直接插入
void InsertSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//直接选择排序
void SelectSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a, int begin, int end);