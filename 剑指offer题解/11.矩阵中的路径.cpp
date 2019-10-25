/*
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�

ע�⣺

�����·����Ϊ�գ�
���г��ֵ��ַ���Ϊ��дӢ����ĸ��
����
matrix=
[
  ["A","B","C","E"],
  ["S","F","C","S"],
  ["A","D","E","E"]
]

str="BCCE" , return "true" 
str="ASAE" , return "false"
------------------------------------
(DFS) O(n^2*3^k)
��������������У�����Ҫ�ľ��ǿ��Ǻ�����˳��

������ö�ٵ��ʵ���㣬Ȼ������ö�ٵ��ʵ�ÿ����ĸ��
��������Ҫ���Ѿ�ʹ�ù�����ĸ�ĳ�һ��������ĸ���Ա����ظ�ʹ���ַ���

ʱ�临�Ӷȷ������������һ���� n^2 �������ʵ�ÿ����ĸһ�������������ĸ��������ѡ�񣬵����ڲ����߻�ͷ·�����Գ��˵�������ĸ�⣬��������ѡ��������ʱ�临�Ӷ��� O(n^2*3^k)��
*/
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool hasPath(vector<vector<char>> &matrix, string str)
    {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (dfs(matrix, str, 0, i, j))
                    return true;
        return false;
    }

    //u:��ǰö�ٵ��ַ�����ö��·������   x,y ��ǰö�ٵ��յ�
    bool dfs(vector<vector<char>> &matrix, string &str, int u, int x, int y)
    {
        if (matrix[x][y] != str[u])
            return false;
        if (u == str.size() - 1) //�Ѿ��ҵ���ö�ٳ��Ⱥ�Ŀ�괮�������
            return true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //���������ĸ�����
        char t = matrix[x][y];
        matrix[x][y] = '*';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size())
            {
                if (dfs(matrix, str, u + 1, a, b))
                    return true;
            }
        }
        matrix[x][y] = t;
        return false;
    }
};