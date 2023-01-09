#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;

	return node;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)

	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SListPopBack(SListNode** pplist)
{
	SListNode* prev = NULL;
	SListNode* tail = *pplist;


	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}


void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);



	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

void SListPopFront(SListNode** pplist)
{
	


	SListNode* first = *pplist;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = first->next;
		free(first);
		*pplist = next;
	}
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* next = pos->next;

	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* next = pos->next;
	
	if (next != NULL)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}