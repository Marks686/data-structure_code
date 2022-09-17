#pragma once
#include<stdio.h>
#include<stdlib.h>
//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__
//#endif

//静态的顺序表-->大小是固定的-->不知道要存多少数据？
#define N 10
typedef int SLDataType;//SLDataType数据类型//typedef类型的重定义
struct SeqList
{
	SLDataType a[N];
	int size;//存储数据的个数
};

//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;     //存储数据的个数
	int capacity; //存储空间的大小
}SL;

//void SeqListInt(SL* sl);

//初始化
void SLInit(SL* psl);

//销毁
void SLDestory(SL* psl);


