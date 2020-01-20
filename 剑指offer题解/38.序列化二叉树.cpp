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
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode *root, string &res)
    {
        if (!root)
        {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs(root->left, res);
        dfs(root->right, res);
    }
    // Decodes your encoded data to tree.

    TreeNode *deserialize(string data)
    {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode *dfs_d(string data, int &u)
    {
        if (u == data.size())
            return NULL;
        int k = u;
        while (data[k] != ' ')
            k++;
        if (data[u] == 'n')
        {
            u = k + 1;
            return NULL;
        }

        int val = 0;
        for (int i = u; i < k; i++)
        {
            if (data[i] == '-')
            {
                i++;
                val = val * 10 + data[i] - '0'; //把数字串转成数字
            }
            else
            {
                val = val * 10 + data[i] - '0'; //把数字串转成数字
            }
        }

        if (data[u] == '-')
            val = -val;

        u = k + 1;

        auto root = new TreeNode(val);
        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);
        return root;
    }
};