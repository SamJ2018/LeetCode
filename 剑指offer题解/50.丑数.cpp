/*
我们把只包含质因子2、3和5的数称作丑数（Ugly Number）。

例如6、8都是丑数，但14不是，因为它包含质因子7。

求第n个丑数的值。

样例
输入：5

输出：5
注意：习惯上我们把1当做第一个丑数。
------------------------------------------

*/
#include <vector>
using namespace std;
class Solution
{
public:
    int getUglyNumber(int n)
    {
        vector<int> q(1, 1);
        int i = 0, j = 0, k = 0;
        while (--n)
        {
            int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5));
            q.push_back(t);
            if (q[i] * 2 == t)
                i++;
            if (q[j] * 3 == t)
                j++;
            if (q[k] * 5 == t)
                k++;
        }
        return q.back();
    }
};