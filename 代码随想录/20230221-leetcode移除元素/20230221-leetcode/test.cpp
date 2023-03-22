//26. 删除有序数组中的重复项
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        while (fast < nums.size())
        {
            if (nums[slow] != nums[fast])
            {
                nums[++slow] = nums[fast];
            }
            else
            {
                fast++;
            }
        }
        return slow + 1;
    }
};
//283. 移动零
//https://leetcode.cn/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != 0)
            {
                swap(nums[slow++], nums[fast]);
            }
            fast++;
        }

    }
};
//如果不能用库函数自己就写一个swap

class Solution {
public:
    void swap1(int* a, int* b)
    {
        int tmp = 0;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void moveZeroes(vector<int>& nums) {

        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != 0)
            {
                swap1(&nums[slow], &nums[fast]);
                slow++;
            }
            fast++;
        }

    }
};

//844. 比较含退格的字符串
//https://leetcode.cn/problems/backspace-string-compare/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if (skipS > 0)
                {
                    skipS--;
                    i--;
                }
                else
                {
                    break;
                }
            }

            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if (skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                {
                    break;
                }
            }


            if (i >= 0 && j >= 0)
            {
                if (s[i] != t[j])
                {
                    return false;
                }

            }
            else
            {
                if (i >= 0 || j >= 0)
                {
                    return false;
                }
            }
            i--;
            j--;
        }
        return true;
    }
};