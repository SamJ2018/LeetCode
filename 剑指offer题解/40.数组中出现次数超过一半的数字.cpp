/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

假设数组非空，并且一定存在满足条件的数字。

思考题：

假设要求只能使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？
样例
输入：[1,2,1,1,3]

输出：1
--------------------------------------------------------

*/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int moreThanHalfNum_Solution(vector<int> &nums)
    {
        int cnt = 0, val = -1;
        for (auto x : nums)
        {
            if (!cnt)
                val = x, cnt = 1;
            else
                cnt = x == val ? ++cnt : --cnt;
        }
        return val;
    }

    //解法二：用hashtable为每个数计数
    int majorityElement2(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            if (++counter[num] > nums.size() / 2)
            {
                return num;
            }
        }
        return 0;
    }

    //解法一改进：边界条件
    int majorityElement3(vector<int> &nums)
    {
        int i, cnt, c = nums[0];
        for (i = 1; i < nums.size(); i++)
            if (nums[i] == c)
                cnt++;
            else if (cnt > 0 && nums[i])
                --cnt;
            else
                cnt = 1, c = nums[i];

        if (cnt > 0)
            for (i = cnt = 0; i < nums.size(); i++)
                if (nums[i] == c)
                    cnt++;

        if (cnt > nums.size() / 2)
            return c;
        return -1;
    }
};