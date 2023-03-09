#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	//1、空
	//2、非空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SLTNode* tail = *pphead;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	//温柔的检查
	if (*pphead == NULL)
	{
		return;
	}

	//暴力的检查
	//assert(*pphead != NULL);

	//1.一个节点
	//2.多个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找尾
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL);
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	//温柔的检查
	if (*pphead == NULL)
	{
		return;
	}

	//暴力的检查
	//assert(*pphead != NULL);

	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;

	free(del);
	del = NULL;
}


void SListDestory(SLTNode* phead)
{
	assert(pphead);

	SLTNode* cur = *pphead;
	//while(cur != NULL)
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
