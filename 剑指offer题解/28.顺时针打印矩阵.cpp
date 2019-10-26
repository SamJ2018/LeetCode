/*

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

样例
输入：
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]

输出：[1,2,3,4,8,12,11,10,9,5,6,7]

-------------------------------------------
算法
(模拟) O(n2)
我们顺时针定义四个方向：上右下左。
从左上角开始遍历，先往右走，走到不能走为止，然后更改到下个方向，再走到不能走为止，依次类推，遍历 n^2 个格子后停止。

时间复杂度
矩阵中每个格子遍历一次，所以总时间复杂度是 O(n^2)。
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> res;
        int n = matrix.size();
        if (!n)
            return res;
        int m = matrix[0].size();

        vector<vector<bool>> st(n, vector<bool>(m, false));
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, d = 1; //注意d
        for (int i = 0; i < n * m; i++)
        {
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b])
            {
                d = (d + 1) % 4;
                a = x + dx[d], b = dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};