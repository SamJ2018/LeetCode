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