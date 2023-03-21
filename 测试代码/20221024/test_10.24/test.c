#define _CRT_SECURE_NO_WARNINGS
#include<assert.h>
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL, * tail = NULL;
	while (cur)
	{
		if (cur->val != val)
		{
			if (tail == NULL)
			{
				newhead = tail = cur;
			}
			else
			{
				tail->next = cur;
				tail = tail->next;
			}
			cur = cur->next;
		}
		else
		{
			struct ListNode* del = cur;
			cur = cur->next;
			free(del);
		}
	}
	if (tail != NULL)
	{
		tail->next = NULL;
	}
	return newhead;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
	guard->next = NULL;
	struct ListNode* tail = guard;
	struct ListNode* cur1 = list1, * cur2 = list2;
	while (cur1 && cur2)
	{
		if (cur1->val < cur2->val)
		{
			tail->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tail->next = cur2;
			cur2 = cur2->next;

		}
		tail = tail->next;
	}
	if (cur1)
	{
		tail->next = cur1;
	}
	if (cur2)
	{
		tail->next = cur2;
	}
	struct ListNode* head = guard->next;
	free(guard);
	return head;
}
int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n1);
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n2);
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n3);
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n4);
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n5);
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n6);
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n7);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	n1->val = 1; 
	n2->val = 2;
	n3->val = 6;
	n4->val = 3;
	n5->val = 4;
	n6->val = 5;
	n7->val = 6;

	struct ListNode* head = removeElements(n1, 6);

	return 0;
}