/*
��ʵ�������������ֱ��������л��ͷ����л���������

����Ҫȷ���������������л�Ϊ�ַ��������ҿ��Խ����ַ��������л�Ϊԭʼ���ṹ��

����
��������л����µĶ�����
    8
   / \
  12  2
     / \
    6   4

Ϊ��"[8, 12, 2, null, null, 6, 4, null, null, null, null]"

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
                val = val * 10 + data[i] - '0'; //�����ִ�ת������
            }
            else
            {
                val = val * 10 + data[i] - '0'; //�����ִ�ת������
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