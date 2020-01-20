/*
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����

������������[3, 32, 321]�����ӡ����3���������ųɵ���С����321323��

����
���룺[3, 32, 321]

�����321323
ע�⣺������ֵĸ�ʽΪ�ַ�����
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