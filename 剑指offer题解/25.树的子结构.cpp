/*
输入两棵二叉树A，B，判断B是不是A的子结构。

我们规定空树不是任何树的子结构。

样例
树A：

     8
    / \
   8   7
  / \
 9   2
    / \
   4   7
树B：

   8
  / \
 9   2
返回 true ,因为B是A的子结构。

----
算法
(二叉树，递归) O(nm)
代码分为两个部分：

遍历树A中的所有非空节点R；
判断树A中以R为根节点的子树是不是包含和树B一样的结构，且我们从根节点开始匹配；
对于第一部分，我们直接递归遍历树A即可，遇到非空节点后，就进行第二部分的判断。

对于第二部分，我们同时从根节点开始遍历两棵子树：

如果树B中的节点为空，则表示当前分支是匹配的，返回true；
如果树A中的节点为空，但树B中的节点不为空，则说明不匹配，返回false；
如果两个节点都不为空，但数值不同，则说明不匹配，返回false；
否则说明当前这个点是匹配的，然后递归判断左子树和右子树是否分别匹配即可；
时间复杂度
最坏情况下，我们对于树A中的每个节点都要递归判断一遍，每次判断在最坏情况下需要遍历完树B中的所有节点。
所以时间复杂度是 O(nm)，其中 n 是树A中的节点数， m 是树B中的节点数。
*/

#include <cstdlib>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool hasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false; //任一子树为空
        if (isPart(pRoot1, pRoot2))
            return true;
        return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }

    bool isPart(TreeNode *p1, TreeNode *p2)
    {
        if (!p2)
            return true;
        if (!p1 || p1->val != p2->val)
            return false;
        return isPart(p1->left, p2->left) && isPart(p1->right, p2->right);
    }
};