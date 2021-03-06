/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

例如输入数组[3, 32, 321]，则打印出这3个数字能排成的最小数字321323。

样例
输入：[3, 32, 321]

输出：321323
注意：输出数字的格式为字符串。
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(int a, int b)
    {
        auto as = to_string(a), bs = to_string(b);
        return as + bs < bs + as;
    }

    string printMinNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (auto x : nums)
            res += to_string(x);
        return res;
    }
};