//367. 有效的完全平方数
//https://leetcode.cn/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right)
        {
            long long mid = left + ((right - left) / 2);
            if (mid * mid < num)
            {
                left = mid + 1;
            }
            else if (mid * mid > num)
            {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
