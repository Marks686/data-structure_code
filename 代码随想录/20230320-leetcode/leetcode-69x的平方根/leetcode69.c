//https://leetcode.cn/problems/sqrtx/
//69. x 的平方根 
class Solution {
public:
    int mySqrt(int x) {
        long i = 1;
        while (i * i <= x)
        {
            i++;
        }
        return i - 1;
    }
};