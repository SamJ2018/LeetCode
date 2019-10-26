/*
请实现一个函数按照之字形顺序从上向下打印二叉树。

即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

样例
输入如下图所示二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]
    8
   / \
  12  2
     / \
    6   4
输出：[[8], [2, 12], [6, 4]]

---------------------------------
算法
(BFS) O(n)
宽度优先遍历，一层一层来做。即：

将根节点插入队列中；
创建一个新队列，用来按顺序保存下一层的所有子节点；
对于当前队列中的所有节点，按顺序依次将儿子插入新队列；
按从左到右、从右到左的顺序交替保存队列中节点的值；
重复步骤2-4，直到队列为空为止。
时间复杂度
树中每个节点仅会进队出队一次，所以时间复杂度是 O(n)。
*/
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> printFromTopToBottom(TreeNode *root)
    {
    }
};