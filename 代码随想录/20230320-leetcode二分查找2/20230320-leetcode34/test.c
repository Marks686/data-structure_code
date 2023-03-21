
//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
//34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBoder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        if (leftBoder == -2 || rightBorder == -2) {
            return { -1,-1 };
        }

        if (rightBorder - leftBoder > 1) {
            return { leftBoder + 1, rightBorder - 1 };
        }

        return { -1,-1 };
    }
    int getRightBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBoder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] >= target)
            {
                right = mid - 1;
                leftBoder = right;
            }
            else
            {
                left = mid + 1;
            }
        }
        return leftBoder;
    }
};