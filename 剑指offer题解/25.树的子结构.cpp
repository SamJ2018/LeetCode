/*
�������ö�����A��B���ж�B�ǲ���A���ӽṹ��

���ǹ涨���������κ������ӽṹ��

����
��A��

     8
    / \
   8   7
  / \
 9   2
    / \
   4   7
��B��

   8
  / \
 9   2
���� true ,��ΪB��A���ӽṹ��

----
�㷨
(���������ݹ�) O(nm)
�����Ϊ�������֣�

������A�е����зǿսڵ�R��
�ж���A����RΪ���ڵ�������ǲ��ǰ�������Bһ���Ľṹ�������ǴӸ��ڵ㿪ʼƥ�䣻
���ڵ�һ���֣�����ֱ�ӵݹ������A���ɣ������ǿսڵ�󣬾ͽ��еڶ����ֵ��жϡ�

���ڵڶ����֣�����ͬʱ�Ӹ��ڵ㿪ʼ��������������

�����B�еĽڵ�Ϊ�գ����ʾ��ǰ��֧��ƥ��ģ�����true��
�����A�еĽڵ�Ϊ�գ�����B�еĽڵ㲻Ϊ�գ���˵����ƥ�䣬����false��
��������ڵ㶼��Ϊ�գ�����ֵ��ͬ����˵����ƥ�䣬����false��
����˵����ǰ�������ƥ��ģ�Ȼ��ݹ��ж����������������Ƿ�ֱ�ƥ�伴�ɣ�
ʱ�临�Ӷ�
�����£����Ƕ�����A�е�ÿ���ڵ㶼Ҫ�ݹ��ж�һ�飬ÿ���ж�����������Ҫ��������B�е����нڵ㡣
����ʱ�临�Ӷ��� O(nm)������ n ����A�еĽڵ����� m ����B�еĽڵ�����
*/

#include <cstdlib>
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
    bool hasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false; //��һ����Ϊ��
        if (isPart(pRoot1, pRoot2))
            return true;
        return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }

    bool isPart(TreeNode *p1, TreeNode *p2)
    {
        if (!p2)
            return true;
        if (!p1 || p1->val != p2->val)
            return false;
        return isPart(p1->left, p2->left) && isPart(p1->right, p2->right);
    }
};