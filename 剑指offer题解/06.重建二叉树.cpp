/*
输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。

注意:

二叉树中每个节点的值都互不相同；
输入的前序遍历和中序遍历一定合法；
样例
给定：
前序遍历是：[3, 9, 20, 15, 7]
中序遍历是：[9, 3, 15, 20, 7]

返回：[3, 9, 20, null, null, 15, 7, null, null, null, null]
返回的二叉树如下所示：
    3
   / \
  9  20
    /  \
   15   7
--------------------------------------------------------
(递归) O(n)
递归建立整棵二叉树：先递归创建左右子树，然后创建根节点，并让指针指向两棵子树。

具体步骤如下：

先利用前序遍历找根节点：前序遍历的第一个数，就是根节点的值；
在中序遍历中找到根节点的位置 k，则 k 左边是左子树的中序遍历，右边是右子树的中序遍历；
假设左子树的中序遍历的长度是 l，则在前序遍历中，根节点后面的 l 个数，是左子树的前序遍历，剩下的数是右子树的前序遍历；
有了左右子树的前序遍历和中序遍历，我们可以先递归创建出左右子树，然后再创建根节点；
时间复杂度分析
我们在初始化时，用哈希表(unordered_map<int,int>)记录每个值在中序遍历中的位置，这样我们在递归到每个节点时，在中序遍历中查找根节点位置的操作，只需要 O(1)的时间。此时，创建每个节点需要的时间是 O(1)，所以总时间复杂度是 O(n)。
*/

#include <bits/stdc++.h>
using namespace std;

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
    map<int, int> hash;
    vector<int> preorder, inorder;
    TreeNode *buildTree(vector<int> &_preorder, vector<int> &_inorder)
    {
        preorder = _preorder, inorder = _inorder;
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *dfs(int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return nullptr;
        auto root = new TreeNode(preorder[pl]); //前序遍历的根结点就是第一个结点
        int k = hash[root->val];
        auto left = dfs(pl + 1, pl + k - il, il, k - 1); //递归  左子树前序遍历和中序遍历
        auto right = dfs(pl + k - il + 1, pr, k + 1, ir);
        root->left = left, root->right = right;
        return root;
    }
};