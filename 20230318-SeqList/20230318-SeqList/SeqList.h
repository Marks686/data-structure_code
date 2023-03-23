#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SLInit(SL* psl);
void SLDestory(SL* psl);
void SLPrint(const SL* psl);

void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

// 没有找到就返回-1
int SLFind(SL* psl, SLDataType x);

// 顺序表在pos位置插入x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// 顺序表删除pos位置的值
void SLErase(SL* psl, size_t pos);

void SLModify(SL* psl, size_t pos, SLDataType x);
