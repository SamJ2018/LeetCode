/*
����n���������ҳ�������С��k������

ע�⣺

���ݱ�֤kһ��С�ڵ�����������ĳ���;
���������Ԫ���밴��С����˳������;
����
���룺[1,2,3,4,5,6,7,8] , k=4

�����[1,2,3,4]

------------------------------
����һ���󶥶ѣ�����k��Ԫ�أ��������飬�����ǰԪ�رȶѶ�Ԫ��С����ô�Ͱ�Ԫ�طŽ�ȥ��Ȼ��ѶѶ�Ԫ��pop������֤���ﱣ��k����С��Ԫ�ء�
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k)
    {
        priority_queue<int> heap;
        for (auto x : input)
        {
            heap.push(x);
            if (heap.size() > k)
                heap.pop();
        }
        vector<int> res;
        while (heap.size())
            res.push_back(heap.top()), heap.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};