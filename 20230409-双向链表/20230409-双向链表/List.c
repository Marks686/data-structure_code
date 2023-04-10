#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = x;
	node->next = NULL;
	node->prev = NULL;
}

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;

	return head;
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

void ListDestroy(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(pHead);
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
}


void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead->next, x);
}

void PushPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->prev);
}

void ListPopFront(ListNode* pHead)
{
	ListErase(pHead->next);
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}

void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
}