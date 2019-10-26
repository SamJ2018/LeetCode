/*
输入一个二叉树，将它变换为它的镜像。

样例
输入树：
      8
     / \
    6  10
   / \ / \
  5  7 9 11

 [8,6,10,5,7,9,11,null,null,null,null,null,null,null,null] 
输出树：
      8
     / \
    10  6
   / \ / \
  11 9 7  5

 [8,10,6,11,9,7,5,null,null,null,null,null,null,null,null]

 ----------------------------------------------------------
算法
(二叉树，递归) O(n)
仔细观察原树和镜像之后的树：

原树：
      8
     / \
    6  10
   / \ / \
  5  7 9 11

镜像后的树：
      8
     / \
    10  6
   / \ / \
  11 9 7  5
我们可以发现镜像后的树就是将原树的所有节点的左右儿子互换！

所以我们递归遍历原树的所有节点，将每个节点的左右儿子互换即可。

时间复杂度
原树仅被遍历一次，所以时间复杂度是 O(n)。
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
    void mirror(TreeNode *root)
    {
        if (!root)
            return;
        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
    
    void swap(TreeNode *left, TreeNode *right)
    {
        auto t = left;
        left = right;
        right = t;
    }
};