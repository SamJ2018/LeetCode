/*
����һ�����֣����ܰ����ظ����֣�����������е����з�ʽ��

����
���룺[1,2,3]

�����
      [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
      ]
-------------------------------
˼·�� 1 1 2 2 3    �涨����ظ������ں��棬�� _ _ 1 _ 1    _ 2 1 _ 1  _ 2 1 2 1
ע��2�����ȷ��ڵ�4��λ��

(����) O(n!)
�������ظ�Ԫ�صĴ��ڣ�������ö��˳��� Permutations ��ͬ��

�Ƚ���������С��������������ͬ����������һ��
����������ö��ÿ������ÿ�ν�������һ����λ�ϣ�
������ͬ����������Ϊ���򣬾Ϳ��Ա����ظ����㣺������dfsʱ��¼һ�������״̬����¼��һ����ͬ����ŵ�λ�� start��������ö�ٵ�ǰ��ʱ��ֻö�� start+1,start+2,��,n��Щλ�á�
��Ҫ���ǵݹ�ǰ�ͻ���ʱ����״̬���и��¡�
ʱ�临�Ӷȷ����������������һ�㹲 n! ���ڵ㣬ǰ�����в��һ��Ľڵ�������������һ��ڵ���������С�������Ժ��ԡ������һ��ڵ��¼�����ļ�������O(n)��������ʱ�临�Ӷ��� O(n��n!)��
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  vector<vector<int>> ans;
  vector<int> path;

public:
  vector<vector<int>>
  permutation(vector<int> &nums)
  {
    path.resize(nums.size());
    sort(nums.begin(), nums.end());
    dfs(nums, 0, 0, 0); //��һ��������������ʾ�Ӵ治����
    return ans;
  }

  void dfs(vector<int> &nums, int u, int start, int state) //state:ÿ������״̬�������ظ������ж�
  {
    if (u == nums.size())
    {
      ans.push_back(path);
      return;
    }
    if (!u || nums[u] != nums[u - 1])
      start = 0; //����ǵ�һ���� ���������û���ظ������ź��򣩣�����Դ�0��ʼö��
    for (int i = start; i < nums.size(); i++)
      if (!(state >> i & 1)) //�ж�state�Ķ��������ĵ�iλ�Ƿ�Ϊ1
      {
        path[i] = nums[u];
        dfs(nums, u + 1, i + 1, state + (1 << i)); //��state�ĵ�iλ��Ϊ1   1<<i ��iλ��Ϊ1
      }
  }
};