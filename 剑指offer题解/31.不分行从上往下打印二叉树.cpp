/*
�������´�ӡ����������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��

����
��������ͼ��ʾ������[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4

�����[8, 12, 2, 6, 4]

-------------------------------------------------------
�㷨
(BFS) O(n)
���ǴӸ��ڵ㿪ʼ��������ȵ�˳�������������ÿ������չ����ӣ�����չ�Ҷ��ӡ�

�������ǻ᣺

����չ���ڵ㣻
��������չ���ڵ�����Ҷ��ӣ�Ҳ���Ǵ�������չ�ڶ���ڵ㣻
�����δ�������չ������ڵ㣻
��������
����BFS��˳����������ĿҪ���˳��

ʱ�临�Ӷ�
BFSʱÿ���ڵ��������һ�Σ�����ʱ�临�Ӷ��� O(n)��
*/
#include <vector>
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
    vector<int> printFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()){
            auto t= q.front();
            q.pop();
            res.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return res;
    }
};