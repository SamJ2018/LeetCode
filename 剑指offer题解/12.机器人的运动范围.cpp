/*
������һ�� m �к� n �еķ��񣬺������귶Χ�ֱ��� 0~m-1 �� 0~n-1��

һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��

���ǲ��ܽ�������������������λ֮�ʹ��� k �ĸ��ӡ�

���ʸû������ܹ��ﵽ���ٸ����ӣ�

����1
���룺k=7, m=4, n=5
�����20

����2
���룺k=18, m=40, n=40

�����1484

���ͣ���kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
      ���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19��
ע��:

0<=m<=50
0<=n<=50
0<=k<=100
------------------------------------------------------------------------
�㷨
(BFS) O(nm)
����һ�����͵Ŀ�������������⣬���Ǵ� (0, 0) �㿪ʼ��ÿ�γ����������ĸ�������չ�µĽڵ㼴�ɡ�

��չʱ��Ҫע���µĽڵ���Ҫ��������������

֮ǰû�б���������������ø�bool�������жϣ�
û���߳��߽磻
��������ĸ�λ����֮��С�� k��
���𰸾������б������ĺϷ��Ľڵ������

ʱ�临�Ӷ�
ÿ���ڵ����ֻ�����һ�Σ�����ʱ�临�ӶȲ��ᳬ�������еĽڵ������
�����»���������е����е㣬����ʱ�临�ӶȾ��� O(nm)��
*/
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int getSingleSum(int x)
    {
        int s = 0;
        while (x)
            s += x % 10, x /= 10;
        return s;
    }
    int getSum(pair<int, int> p)
    {
        //���ڼ���λ��
        return getSingleSum(p.first) + getSingleSum(p.second);
    }
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0; //ͳ�ƽ��
        if (!rows || !cols)
            return 0;

        vector<vector<bool>> st(rows, vector<bool>(cols));
        queue<pair<int, int>> q;

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        q.push({0, 0});
        while (q.size())
        {
            auto t = q.front();
            q.pop();

            if (getSum(t) > threshold || st[t.first][t.second])
                continue; //�Ѿ��������ˣ�������һ�����
            res++;
            st[t.first][t.second] = true;

            for (int i = 0; i < 4; i++)
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols)
                {
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};