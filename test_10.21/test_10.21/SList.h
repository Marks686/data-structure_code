#pragma once
#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data; 
	struct SListNode* next;
}SLTNode;

//创建malloc结点的指针
SLTNode* BuySLTNode(SLTDateType x);
//链表打印
void SListPrint(SLTNode* phead);   
//链表销毁
void SListDestory(SLTNode* phead);
//链表的头部插入
void SListPushFront(SLTNode** pphead, SLTDateType x);
//尾插
void SListPushBack(SLTNode** pphead, SLTDateType x);
//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphead);
//链表的查找
SLTNode* SListFind(SLTNode* phead,SLTDateType x);
//某个位置去插入  ---- 在pos之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//在pos之后插入
void SListInsertAfter(SLTNode* pos, SLTDateType x);
//某个位置去删除---- 删除pos
void SListErase(SLTNode** pphead, SLTNode* pos);
