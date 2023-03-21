#include <stdio.h>


//https://leetcode.cn/problems/merge-two-sorted-lists/
//21. 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
	guard->next = NULL;
	struct ListNode* tail = guard;
	struct ListNode* cur1 = list1, *cur2 = list2;
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
	return 0;
}