/*
在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。

你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格直到到达棋盘的右下角。

给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？

注意：

m,n>0
样例：

输入：
[
  [2,3,1],
  [1,7,1],
  [4,6,1]
]

输出：19

解释：沿着路径 2→3→7→6→1 可以得到拿到最大价值礼物。

------------------------------------------------
算法1
(动态规划) O(n2)O
dp[i][j] 代表走到（i，j）这个位置的最大价值
由于只能向下向右走，所以（i，j）这个位置只能从左边和上边过来，所以dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j],即从左边和上边这两个位置选一个较大的加上本位置的价值，即可。
*/
#include <vector>
using namespace std;
class Solution
{
public:
  int getMaxValue(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
    return f[n][m];
  }
};