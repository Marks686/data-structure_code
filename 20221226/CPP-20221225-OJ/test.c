#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//https://leetcode.cn/problems/remove-linked-list-elements/
// 方法1：
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* cur = head, * prev = NULL;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            //1.头删
//            if (cur == head)
//            {
//                head = head->next;
//                free(cur);
//                cur = head;
//            }
//            else//2.非头删
//            {
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}
//方法2：
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL, * tail = NULL;
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            if (tail == NULL)
//            {
//                newhead = tail = cur;
//            }
//            else
//            {
//                tail->next = cur;
//                tail = tail->next;
//            }
//
//            cur = cur->next;
//        }
//        else
//        {
//            struct ListNode* del = cur;
//            cur = cur->next;
//            free(del);
//        }
//    }
//    if (tail)
//    {
//        tail->next = NULL;
//    }
//    return newhead;
//}
//https://leetcode.cn/problems/merge-two-sorted-lists/
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
//    guard->next = NULL;
//    struct ListNode* cur1 = list1, * cur2 = list2;
//    struct ListNode* tail = guard;
//    while (cur1 && cur2)
//    {
//        if (cur1->val < cur2->val)
//        {
//            tail->next = cur1;
//            cur1 = cur1->next;
//        }
//        else
//        {
//            tail->next = cur2;
//            cur2 = cur2->next;
//        }
//        tail = tail->next;
//    }
//    if (cur1)
//    {
//        tail->next = cur1;
//    }
//    if (cur2)
//    {
//        tail->next = cur2;
//    }
//    struct ListNode* head = guard->next;
//    free(guard);
//    return head;
//}

//https://leetcode.cn/problems/reverse-linked-list/
// 方法1：
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* newhead = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
//}
//方法2：
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = NULL;
//    while (n2)
//    {
//        n3 = n2->next;
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//    }
//    return n1;
//}
//https://leetcode.cn/problems/middle-of-the-linked-list/
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}