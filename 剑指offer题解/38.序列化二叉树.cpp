/*
请实现两个函数，分别用来序列化和反序列化二叉树。

您需要确保二叉树可以序列化为字符串，并且可以将此字符串反序列化为原始树结构。

样例
你可以序列化如下的二叉树
    8
   / \
  12  2
     / \
    6   4

为："[8, 12, 2, null, null, 6, 4, null, null, null, null]"

-------------------------------

*/
#include <string>
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
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
    }
};