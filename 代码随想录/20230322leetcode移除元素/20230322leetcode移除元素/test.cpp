//977. 有序数组的平方
//https://leetcode.cn/problems/squares-of-a-sorted-array/



//法1：
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (auto num : nums)
        {
            ans.push_back(num * num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};



