/*
��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�

���һ�ö����������ľ���һ������ô���ǶԳƵġ�

����
����ͼ��ʾ������[1,2,2,3,4,4,3,null,null,null,null,null,null,null,null]Ϊ�Գƶ�������
    1
   / \
  2   2
 / \ / \
3  4 4  3

����ͼ��ʾ������[1,2,2,null,4,4,3,null,null,null,null,null,null]���ǶԳƶ�������
    1
   / \
  2   2
   \ / \
   4 4  3
-------------------------------------------------------------------------------
�㷨1
(���������ݹ�) O(n)
�ݹ��ж����������Ƿ�Ϊ����

����������Ϊ�����ҽ�����

���������ĸ��ڵ�ֵ��ȣ�
��һ���������������͵ڶ�����������������Ϊ�����ҵ�һ���������������͵ڶ�����������������Ϊ����
ʱ�临�Ӷ�
���ϵ���ÿ���ڵ��������һ�飬����ʱ�临�Ӷ��� O(n)��
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
            return true; //����Ĭ�϶Գ�
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return !p && !q; //��һ����Ϊ��ʱ����Ҫ��һ����ҲΪ��
        if (p->val != q->val)
            return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};