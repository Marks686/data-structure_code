//OR36 链表的回文结构
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        int a[900] = { 0 };
        ListNode* cur = A;
        int n = 0;
        while (cur)
        {
            a[n++] = cur->val;
            cur = cur->next;
        }
        int begin = 0;
        int end = n - 1;
        while (begin < end)
        {
            if (a[begin] != a[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};

