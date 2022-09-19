#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N 10
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SLInit(SL* psl);

void SLPrint(const SL* psl);

void SLDestory(SL* psl);

void SLPushBack(SL* psl, SLDataType x);

void SLPushFront(SL* psl, SLDataType x);

void SLPopBack(SL* psl);

void SLPopFront(SL* psl);

int SLFind (SL* psl, SLDataType x);

void SLInsert(SL* psl, size_t pos, SLDataType x);

void SLErase(SL* psl, size_t pos);

void SLModify(SL* psl, size_t pos, SLDataType x);
