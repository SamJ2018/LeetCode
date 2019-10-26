/*

���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��

����ѹ��ջ���������־�����ȡ�

��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�

ע�⣺���������г��Ȳ�������Ϊ������һ��ջ��ѹ�롢�������С����������ж�Ϊ�գ�����Ϊ��һ��ջ��ѹ�롢�������С�

����
���룺[1,2,3,4,5]
      [4,5,3,2,1]

�����true

------------------------------------------
�㷨1
(ջ) O(n)
��һ����ջs��ģ��ʵʱ����ջ������

��for loop������ι����ÿpushһ�����־ͼ����û����pop�����ġ�

������sΪ�գ�����popId==popV.size())��˵��һ��һ���ոպá�

ʱ�临�Ӷȷ�����һ��push n�Σ�pop n�Ρ�
*/

#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return pushV.empty() && popV.empty(); //
        stack<int> s;
        int popId = 0;
        for (int pushId = 0; pushId < pushV.size(); ++pushId)
        {
            s.push(pushV[pushId]);
            while (!s.empty() && s.top() == popV[popId])
            {
                s.pop();
                ++popId;
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};