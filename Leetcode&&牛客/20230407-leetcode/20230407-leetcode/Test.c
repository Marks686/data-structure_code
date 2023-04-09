//160. Ïà½»Á´±í
//https://leetcode.cn/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int a = 0;
    int b = 0;
    struct ListNode* cur1 = headA, * cur2 = headB;
    while (cur1)
    {
        a++;
        cur1 = cur1->next;
    }

    while (cur2)
    {
        b++;
        cur2 = cur2->next;
    }

    int gap = abs(a - b);
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    if (a < b)
    {
        longList = headB;
        shortList = headA;
    }
    while (gap--)
    {
        longList = longList->next;
    }

    while (longList && shortList)
    {
        if (longList == shortList)
        {
            return longList;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;

}