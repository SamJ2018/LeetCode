/*
����һ�ö�����������һ���ڵ㣬���ҳ�����������е���һ���ڵ㡣

ע�⣺

��������Ľڵ�������������е����һ�����򷵻ؿսڵ�;
������һ����Ϊ�գ��Ҹ����Ľڵ�һ�����ǿսڵ㣻
����
�ٶ��������ǣ�[2, 1, 3, null, null, null, null]�� ��������ֵ����2�Ľڵ㡣

��Ӧ����ֵ����3�Ľڵ㡣

���ͣ��ö������Ľṹ���£�2�ĺ�̽ڵ���3��
  2
 / \
1   3

-------------------------------------------------------------------
�㷨
(ģ��) O(h)
�����Ŀ������������������и����ڵ�ĺ�̡�

�����ǰ�ڵ����Ҷ��ӣ����������������Ľڵ���ǵ�ǰ�ڵ�ĺ�̡�����F�ĺ����H��
�����ǰ�ڵ�û���Ҷ��ӣ�����Ҫ����father��һֱ�����ң��ҵ���һ������father����ӵĽڵ㣬�ýڵ��father���ǵ�ǰ�ڵ�ĺ�̡����統ǰ�ڵ���D�����һ����������father����ӵĽڵ���C����C��father����D�ĺ�̡�

ʱ�临�Ӷȷ���
���������һ��������ң��ܹ������Ľڵ��������������ĸ߶ȡ�����ʱ�临�Ӷ��� O(h)������ h �����ĸ߶ȡ�
*/
#include <cstdlib>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *p)
    {
        if (p->right)
        {
            p = p->right;
            while (p->left)
                p = p->left;
            return p;
        }
        while (p->father && p == p->father->right)
            p = p->father;
        return p->father;
    }
};