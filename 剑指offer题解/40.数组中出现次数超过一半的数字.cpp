/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�

��������ǿգ�����һ�������������������֡�

˼���⣺

����Ҫ��ֻ��ʹ�� O(n) ��ʱ��Ͷ��� O(1) �Ŀռ䣬����ô���أ�
����
���룺[1,2,1,1,3]

�����1
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

    //�ⷨ������hashtableΪÿ��������
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

    //�ⷨһ�Ľ����߽�����
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