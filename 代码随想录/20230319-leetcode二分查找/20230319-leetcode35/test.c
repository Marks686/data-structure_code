//35. 搜索插入位置
//https://leetcode.cn/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //二分法：
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return right + 1;
    }
};




class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //暴力法：
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return nums.size();
    }
};