/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。

要求不能创建任何新的结点，只能调整树中结点指针的指向。

注意：

需要返回双向链表最左侧的节点。

-----------------
创建两个结点  pair<N,N> 递归左子树、右子树  
[4,8] 10 [12,16]  
然后让结点8的right指针指向10，10的left指向8。
让10的right指向12，12的left指向10
最后返回左子树最左侧和  右子树的最右侧
*/
#include <map>
#include <cstdlib>
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
    TreeNode *convert(TreeNode *root)
    {
        if (!root)
            return NULL; //如果根结点不存在
        auto sides = dfs(root);
        return sides.first;
    }

    //递归遍历左右子树
    pair<TreeNode *, TreeNode *> dfs(TreeNode *root)
    {
        //左右子树均不存在，root就是双向链表的头尾结点，返回即可
        if (!root->left && !root->right)
            return {root, root};
        //左右子树都存在
        if (root->left && root->right)
        {
            //递归去判断左右子树
            auto lsides = dfs(root->left), rsides = dfs(root->right);
            lsides.second->right = root; //令左子树的最右孩子的right指针指向根，并且
            root->left = lsides.second;  //令根的left指针指向左子树的最右孩子
            root->right = rsides.first;  //同理，修改右子树
            rsides.first->left = root;
            return {lsides.first, rsides.second}; //返回左子树的最左孩子和右子树的最右孩子
        }
        if (root->left)
        {
            auto lsides = dfs(root->left);
            lsides.second->right = root, root->left = lsides.second;
            return {lsides.first, root};
        }
        if (root->right)
        {
            auto rsides = dfs(root->right);
            root->right = rsides.first, rsides.first->left = root;
            return {root, rsides.second};
        }
    }
};