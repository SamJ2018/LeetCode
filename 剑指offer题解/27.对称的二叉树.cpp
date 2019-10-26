/*
请实现一个函数，用来判断一棵二叉树是不是对称的。

如果一棵二叉树和它的镜像一样，那么它是对称的。

样例
如下图所示二叉树[1,2,2,3,4,4,3,null,null,null,null,null,null,null,null]为对称二叉树：
    1
   / \
  2   2
 / \ / \
3  4 4  3

如下图所示二叉树[1,2,2,null,4,4,3,null,null,null,null,null,null]不是对称二叉树：
    1
   / \
  2   2
   \ / \
   4 4  3
-------------------------------------------------------------------------------
算法1
(二叉树，递归) O(n)
递归判断两个子树是否互为镜像。

两个子树互为镜像当且仅当：

两个子树的根节点值相等；
第一棵子树的左子树和第二棵子树的右子树互为镜像，且第一棵子树的右子树和第二棵子树的左子树互为镜像；
时间复杂度
从上到下每个节点仅被遍历一遍，所以时间复杂度是 O(n)。
*/

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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true; //空树默认对称
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return !p && !q; //当一个点为空时，需要另一个点也为空
        if (p->val != q->val)
            return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};