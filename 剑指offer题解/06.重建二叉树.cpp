/*
����һ�ö�����ǰ���������������Ľ�������ؽ��ö�������

ע��:

��������ÿ���ڵ��ֵ��������ͬ��
�����ǰ��������������һ���Ϸ���
����
������
ǰ������ǣ�[3, 9, 20, 15, 7]
��������ǣ�[9, 3, 15, 20, 7]

���أ�[3, 9, 20, null, null, 15, 7, null, null, null, null]
���صĶ�����������ʾ��
    3
   / \
  9  20
    /  \
   15   7
--------------------------------------------------------
(�ݹ�) O(n)
�ݹ齨�����ö��������ȵݹ鴴������������Ȼ�󴴽����ڵ㣬����ָ��ָ������������

���岽�����£�

������ǰ������Ҹ��ڵ㣺ǰ������ĵ�һ���������Ǹ��ڵ��ֵ��
������������ҵ����ڵ��λ�� k���� k �����������������������ұ��������������������
��������������������ĳ����� l������ǰ������У����ڵ����� l ����������������ǰ�������ʣ�µ�������������ǰ�������
��������������ǰ�������������������ǿ����ȵݹ鴴��������������Ȼ���ٴ������ڵ㣻
ʱ�临�Ӷȷ���
�����ڳ�ʼ��ʱ���ù�ϣ��(unordered_map<int,int>)��¼ÿ��ֵ����������е�λ�ã����������ڵݹ鵽ÿ���ڵ�ʱ������������в��Ҹ��ڵ�λ�õĲ�����ֻ��Ҫ O(1)��ʱ�䡣��ʱ������ÿ���ڵ���Ҫ��ʱ���� O(1)��������ʱ�临�Ӷ��� O(n)��
*/

#include <bits/stdc++.h>
using namespace std;

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
    map<int, int> hash;
    vector<int> preorder, inorder;
    TreeNode *buildTree(vector<int> &_preorder, vector<int> &_inorder)
    {
        preorder = _preorder, inorder = _inorder;
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *dfs(int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return nullptr;
        auto root = new TreeNode(preorder[pl]); //ǰ������ĸ������ǵ�һ�����
        int k = hash[root->val];
        auto left = dfs(pl + 1, pl + k - il, il, k - 1); //�ݹ�  ������ǰ��������������
        auto right = dfs(pl + k - il + 1, pr, k + 1, ir);
        root->left = left, root->right = right;
        return root;
    }
};