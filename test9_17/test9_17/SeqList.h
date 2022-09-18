#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__
//#endif

//静态的顺序表-->大小是固定的-->不知道要存多少数据？
#define N 10
//typedef int SLDataYype;//SLDataType数据类型//typedef类型的重定义
//struct SeqList
//{
//	SLDataYype a[N];
//	int size;//存储数据的个数
//};

//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;     //存储数据的个数
	int capacity; //存储空间的大小
}SL;

//初始化
void SLInit(SL* psl);

//销毁
void SLDestory(SL* psl);

//顺序表的打印
void SLPrint(const SL* psl);

//尾插
void SLPushBack(SL* psl, SLDataType x);

//头插
void SLPushFront(SL* psl, SLDataType x);

//尾删
void SLPopBack(SL* psl);

//头删
void SLPopFront(SL* psl);

// 查找,没有找到返回-1
int SLFind(SL* psl, SLDataType x);

// 在pos位置插入x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// 删除pos位置的值
void SLErase(SL* psl, size_t pos);

//修改
void SLModify(SL* psl, size_t pos,SLDataType x);




