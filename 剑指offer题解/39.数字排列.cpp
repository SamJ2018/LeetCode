/*
输入一组数字（可能包含重复数字），输出其所有的排列方式。

样例
输入：[1,2,3]

输出：
      [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
      ]
-------------------------------
思路： 1 1 2 2 3    规定如果重复都放在后面，如 _ _ 1 _ 1    _ 2 1 _ 1  _ 2 1 2 1
注意2不能先放在第4个位置

(回溯) O(n!)
由于有重复元素的存在，这道题的枚举顺序和 Permutations 不同。

先将所有数从小到大排序，这样相同的数会排在一起；
从左到右依次枚举每个数，每次将它放在一个空位上；
对于相同数，我们人为定序，就可以避免重复计算：我们在dfs时记录一个额外的状态，记录上一个相同数存放的位置 start，我们在枚举当前数时，只枚举 start+1,start+2,…,n这些位置。
不要忘记递归前和回溯时，对状态进行更新。
时间复杂度分析：搜索树中最后一层共 n! 个节点，前面所有层加一块的节点数量相比于最后一层节点数是无穷小量，可以忽略。且最后一层节点记录方案的计算量是O(n)，所以总时间复杂度是 O(n×n!)。
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
    dfs(nums, 0, 0, 0); //用一个二进制数来表示坑存不存在
    return ans;
  }

  void dfs(vector<int> &nums, int u, int start, int state) //state:每个数的状态，用于重复数的判断
  {
    if (u == nums.size())
    {
      ans.push_back(path);
      return;
    }
    if (!u || nums[u] != nums[u - 1])
      start = 0; //如果是第一个数 或者这个数没有重复（已排好序），则可以从0开始枚举
    for (int i = start; i < nums.size(); i++)
      if (!(state >> i & 1)) //判断state的二进制数的第i位是否为1
      {
        path[i] = nums[u];
        dfs(nums, u + 1, i + 1, state + (1 << i)); //把state的第i位置为1   1<<i 把i位置为1
      }
  }
};