/*
����һ�� �ǿ� �������飬�������������Ϊ����Ҳ����Ϊ����

������һ���������Ķ���������һ�������顣

������������ĺ͵����ֵ��

Ҫ��ʱ�临�Ӷ�ΪO(n)��

����
���룺[1, -2, 3, 10, -4, 7, 2, -5]

�����18
----------------------

*/
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN, s = 0;
        for (auto x : nums)
        {
            if (s < 0)
                s = 0;
            s += x;
            res = max(res, s);
        }
        return res;
    }
};