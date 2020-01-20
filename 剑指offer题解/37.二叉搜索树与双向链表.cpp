/*
����һ�ö��������������ö���������ת����һ�������˫������

Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

ע�⣺

��Ҫ����˫�����������Ľڵ㡣

-----------------
�����������  pair<N,N> �ݹ���������������  
[4,8] 10 [12,16]  
Ȼ���ý��8��rightָ��ָ��10��10��leftָ��8��
��10��rightָ��12��12��leftָ��10
��󷵻�������������  �����������Ҳ�
*/
#include <map>
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
    TreeNode *convert(TreeNode *root)
    {
        if (!root)
            return NULL; //�������㲻����
        auto sides = dfs(root);
        return sides.first;
    }

    //�ݹ������������
    pair<TreeNode *, TreeNode *> dfs(TreeNode *root)
    {
        //���������������ڣ�root����˫�������ͷβ��㣬���ؼ���
        if (!root->left && !root->right)
            return {root, root};
        //��������������
        if (root->left && root->right)
        {
            //�ݹ�ȥ�ж���������
            auto lsides = dfs(root->left), rsides = dfs(root->right);
            lsides.second->right = root; //�������������Һ��ӵ�rightָ��ָ���������
            root->left = lsides.second;  //�����leftָ��ָ�������������Һ���
            root->right = rsides.first;  //ͬ���޸�������
            rsides.first->left = root;
            return {lsides.first, rsides.second}; //�����������������Ӻ������������Һ���
        }
        if (root->left)
        {
            auto lsides = dfs(root->left);
            lsides.second->right = root, root->left = lsides.second;
            return {lsides.first, root};
        }
        if (root->right)
        {
            auto rsides = dfs(root->right);
            root->right = rsides.first, rsides.first->left = root;
            return {root, rsides.second};
        }
    }
};