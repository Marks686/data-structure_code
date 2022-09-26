#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType; 
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySLTNode(SLTDataType x);

void SListPrint(SLTNode* phead);

void SListDestory(SLTNode* phead);

void SListPushFront(SLTNode** pphead, SLTDataType x);