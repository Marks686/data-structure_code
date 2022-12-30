#define _CRT_SECURE_NO_WARNINGS
//https://leetcode.cn/problems/linked-list-cycle/
// 141. ª∑–Œ¡¥±Ì
//public class Solution {
//    public boolean hasCycle(ListNode head) {
//        Set<ListNode> seen = new HashSet<ListNode>();
//        while (head != null) {
//            if (!seen.add(head)) {
//                return true;
//            }
//            head = head.next;
//        }
//        return false;
//    }
//}


//public class Solution {
//    public boolean hasCycle(ListNode head) {
//        if (head == null || head.next == null) {
//            return false;
//        }
//        ListNode slow = head;
//        ListNode fast = head.next;
//        while (slow != fast) {
//            if (fast == null || fast.next == null) {
//                return false;
//            }
//            slow = slow.next;
//            fast = fast.next.next;
//        }
//        return true;
//    }
//}



//bool hasCycle(struct ListNode* head)
//{
//    if (!head)
//        return false;
//    struct ListNode* ptr1 = head, * ptr2 = head->next;
//    while (ptr1 && ptr2)
//    {
//        if (ptr1 == ptr2)
//            return true;
//        ptr1 = ptr1->next;
//        ptr2 = ptr2->next;
//        if (!ptr2)
//            break;
//        ptr2 = ptr2->next;
//    }
//    return false;
//}
