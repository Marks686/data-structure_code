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

void SListDestory(SLTNode** phead);

void SListPushBack(SLTNode** pphead, SLTDataType x);

void SListPushFront(SLTNode** pphead, SLTDataType x);

void SListPopBack(SLTNode** pphead);

void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x); 

//在pos之前插入
void SListInsetrt(SLTNode** pphead,SLTNode* pos,SLTDataType x);

//删除pos位置
void SListErase(SLTNode** pphead, SLTNode* pos);



