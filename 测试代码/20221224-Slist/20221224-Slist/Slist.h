#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySLTNode(SLTDataType x);
void SListPrint(SLTNode* phead);
void SListDestory(SLTNode** pphead);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// 在pos之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// 在pos后面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 删除pos位置
void SListErase(SLTNode** pphead, SLTNode* pos);

// 删除pos后面位置
void SListEraseAfter(SLTNode* pos);