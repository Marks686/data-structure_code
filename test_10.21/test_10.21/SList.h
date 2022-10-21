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