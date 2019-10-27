/*
从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

样例
输入如下图所示二叉树[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4

输出：[8, 12, 2, 6, 4]

-------------------------------------------------------
算法
(BFS) O(n)
我们从根节点开始按宽度优先的顺序遍历整棵树，每次先扩展左儿子，再扩展右儿子。

这样我们会：

先扩展根节点；
再依次扩展根节点的左右儿子，也就是从左到右扩展第二层节点；
再依次从左到右扩展第三层节点；
依次类推
所以BFS的顺序就是这道题目要求的顺序。

时间复杂度
BFS时每个节点仅被遍历一次，所以时间复杂度是 O(n)。
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
    vector<int> printFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()){
            auto t= q.front();
            q.pop();
            res.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return res;
    }
};