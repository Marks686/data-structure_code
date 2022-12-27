#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        // write code here
//        struct ListNode* lessGuard, * lessTail, * greaterGuard, * greaterTail;
//        lessGuard = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterGuard = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        lessGuard->next = NULL;
//        greaterGuard->next = NULL;
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = lessTail->next;
//            }
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = greaterTail->next;
//            }
//            cur = cur->next;
//        }
//        lessTail->next = greaterGuard->next;
//        greaterTail->next = NULL;
//
//        pHead = lessGuard->next;
//        free(greaterGuard);
//        free(lessGuard);
//
//        return pHead;
//    }
//};