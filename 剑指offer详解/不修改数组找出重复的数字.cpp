/*
给定一个长度为 n+1 的数组nums，数组中所有的数均在 1?n 的范围内，其中 n≥1。
请找出数组中任意一个重复的数，但不能修改输入的数组。

样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。

返回 2 或 3。
思考题：如果只能使用 O(1) 的额外空间，该怎么做呢？
 */

//思路：遍历nums数组，若下标为i的元素与下标为nums[i]的元素相等则返回，否则交换后继续判断。注意：先要找出不再范围内的数

class Solution
{
public:
    int duplicateInArray(vector<int> &nums)
    {
        int n = nums.size();
        for (auto x : nums)
            if (x < 0 || x >= n)
                return -1;

        for (int i = 0; i < n; i++)
        {
            while (i != nums[i] && nums[nums[i]] != nums[i]) //自己不需要和自己比较
                swap(nums[i], nums[nums[i]]);
            if (nums[i] != i && nums[nums[i]] == nums[i])
                return nums[i];
        }
        return -1; //没有找到
    }
};