/*
����һ���������������������ڵ㣬�����ǵ���͹������ȡ�

һ�����ڵ�����Ƚڵ����������

ע�⣺

����Ķ�������Ϊ�գ�
����������ڵ�һ����Ϊ�գ����Ƕ������еĽڵ㣻
����
������[8, 12, 2, null, null, 6, 4, null, null, null, null]����ͼ��ʾ��
    8
   / \
  12  2
     / \
    6   4

1. �����������ڵ�Ϊ2��12�����������͹�������Ϊ���ڵ�8��

2. �����������ڵ�Ϊ2��6�����������͹�������Ϊ���ڵ�2��
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
    }
};