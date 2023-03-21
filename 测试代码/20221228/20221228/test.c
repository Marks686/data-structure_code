#define _CRT_SECURE_NO_WARNINGS


//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa
// OR36 链表的回文结构
//class PalindromeList {
//public:
//
//    struct ListNode* middleNode(struct ListNode* head) {
//        struct ListNode* slow, * fast;
//        slow = fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    struct ListNode* reverseList(struct ListNode* head) {
//        struct ListNode* n1, * n2, * n3;
//        n1 = NULL;
//        n2 = head;
//        n3 = NULL;
//        while (n2)
//        {
//            n3 = n2->next;
//            n2->next = n1;
//
//            n1 = n2;
//            n2 = n3;
//        }
//        return n1;
//    }
//
//    bool chkPalindrome(ListNode* head) {
//        // write code here
//        struct ListNode* mid = middleNode(head);
//        struct ListNode* rmid = reverseList(mid);
//
//        while (head && rmid)
//        {
//            if (head->val != rmid->val)
//            {
//                return false;
//            }
//
//            head = head->next;
//            rmid = rmid->next;
//        }
//        return true;
//
//    }
//};
//https://leetcode.cn/problems/intersection-of-two-linked-lists/
// 160. 相交链表
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* curA = headA, * curB = headB;
//    int lenA = 1;
//    while (curA->next)
//    {
//        curA = curA->next;
//        ++lenA;
//    }
//
//    int lenB = 1;
//    while (curB->next)
//    {
//        curB = curB->next;
//        ++lenB;
//    }
//
//    if (curA != curB)
//    {
//        return NULL;
//    }
//    struct ListNode* longList = headA, * shortList = headB;
//    if (lenA < lenB)
//    {
//        longList = headB;
//        shortList = headA;
//    }
//    int gap = abs(lenA - lenB);
//
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//    while (longList != shortList)
//    {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//
//    return longList;
//}