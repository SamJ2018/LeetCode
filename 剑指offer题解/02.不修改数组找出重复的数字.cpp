/*
给定一个长度为 n+1 的数组nums，数组中所有的数均在 1?n 的范围内，其中 n≥1。
请找出数组中任意一个重复的数，但不能修改输入的数组。

样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。

返回 2 或 3。
思考题：如果只能使用 O(1) 的额外空间，该怎么做呢？

---------------------------------------------------------------------------
思想：
(分治，抽屉原理) O(nlogn)
这道题目主要应用了抽屉原理和分治的思想。
抽屉原理：n+1 个苹果放在 n 个抽屉里，那么至少有一个抽屉中会放两个苹果。

用在这个题目中就是，一共有 n+1 个数，每个数的取值范围是1到n，所以至少会有一个数出现两次。

然后我们采用分治的思想，将每个数的取值的区间[1, n]划分成[1, n/2]和[n/2+1, n]两个子区间，然后分别统计两个区间中数的个数。
注意这里的区间是指数的 取值范围，而不是 数组下标。

划分之后，左右两个区间里一定至少存在一个区间，区间中数的个数大于区间长度。
这个可以用反证法来说明：如果两个区间中数的个数都小于等于区间长度，那么整个区间中数的个数就小于等于n，和有n+1个数矛盾。

因此我们可以把问题划归到左右两个子区间中的一个，而且由于区间中数的个数大于区间长度，根据抽屉原理，在这个子区间中一定存在某个数出现了两次。

依次类推，每次我们可以把区间长度缩小一半，直到区间长度为1时，我们就找到了答案。

复杂度分析
时间复杂度：每次会将区间长度缩小一半，一共会缩小 O(logn)次。每次统计两个子区间中的数时需要遍历整个数组，时间复杂度是 O(n)。所以总时间复杂度是 O(nlogn)。
空间复杂度：代码中没有用到额外的数组，所以额外的空间复杂度是 O(1)。

*/
#include <vector>
using namespace std;

class Solution
{
public:
    int duplicateInArray(vector<int> &nums)
    {
        int l = 1, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1; //[l,mid] [mid+1,r]
            int s = 0;
            for (auto x : nums)
                s += x >= l && x <= mid;
            if (s > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};

/*
相似扩展：
LeetCode 287. Find the Duplicate Number 
题目描述
给定一个数组 nums 包含 n + 1 个整数，每个整数在 1 到 n 之间，包括 1 和 n。现在假设数组中存在一个重复的数字，找到该重复的数字。

注意
不能修改数组元素，假设数组是只读的。
仅可以使用常数即 O(1) 的额外空间。
时间复杂度需要低于 O(n2)。
数组中仅有一个重复数字，但它可能重复超过 1 次。
样例
Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3


算法
(双指针移动) O(n)
因为每个数都是 1 到 n，所以此题可以当做 Linked List Cycle II 来处理，即 i 位置的 val 和 next 都是 nums[i]。
首先 first 和 second 指针均指向 0 位置，然后 first 每次前进一次，second 每次前进两次。
剩余部分请参考 Linked List Cycle II 中的算法证明。

时间复杂度
参见 Linked List Cycle II 时间复杂度部分，整个数组仅遍历常数次，故时间复杂度为 O(n)。

*/
class Solution2
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int first = 0, second = 0;
        do
        {
            first = nums[first];
            second = nums[nums[second]];
        } while (first != second);

        first = 0;
        while (first != second)
        {
            first = nums[first];
            second = nums[second];
        }
        return first;
    }
};