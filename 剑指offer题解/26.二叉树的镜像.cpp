/*
����һ���������������任Ϊ���ľ���

����
��������
      8
     / \
    6  10
   / \ / \
  5  7 9 11

 [8,6,10,5,7,9,11,null,null,null,null,null,null,null,null] 
�������
      8
     / \
    10  6
   / \ / \
  11 9 7  5

 [8,10,6,11,9,7,5,null,null,null,null,null,null,null,null]

 ----------------------------------------------------------
�㷨
(���������ݹ�) O(n)
��ϸ�۲�ԭ���;���֮�������

ԭ����
      8
     / \
    6  10
   / \ / \
  5  7 9 11

����������
      8
     / \
    10  6
   / \ / \
  11 9 7  5
���ǿ��Է��־����������ǽ�ԭ�������нڵ�����Ҷ��ӻ�����

�������ǵݹ����ԭ�������нڵ㣬��ÿ���ڵ�����Ҷ��ӻ������ɡ�

ʱ�临�Ӷ�
ԭ����������һ�Σ�����ʱ�临�Ӷ��� O(n)��
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