#pragma once
#include<stdio.h>
#include<stdlib.h>

//#ifndef __SEQLIST_H__
//#endif 


//静态的顺序表 -- 不知道要存储多少数据？
#define N 10
//typedef int SLDataType;
// struct SeqList
//{
//	SLDataType a[N];//定长数组
//	int size;//存储数据的个数
//};


//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//动态开辟的数组
	int size;    //存储数据的个数
	int capacity;//存储空间的大小
}SL;

//void SqeListInit(SL sl);
void SLInit(SL sl);
void SLDestory(SL sl);