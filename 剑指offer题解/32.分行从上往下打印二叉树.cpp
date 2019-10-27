/*
���ϵ��°����ӡ��������ͬһ��Ľ�㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�

����
��������ͼ��ʾ������[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4

�����[[8], [12, 2], [6], [4]]

-----------------------------------
�㷨
(BFS) O(n)
������ȱ�����һ��һ������������

�����ڵ��������У�
����һ���¶��У�������˳�򱣴���һ��������ӽڵ㣻
���ڵ�ǰ�����е����нڵ㣬��˳�����ν����Ӽ����¶��У�������ǰ�ڵ��ֵ��¼�ڴ��У�
�ظ�����2-3��ֱ������Ϊ��Ϊֹ��
ʱ�临�Ӷ�
����ÿ���ڵ������ӳ���һ�Σ�����ʱ�临�Ӷ��� O(n)��
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
    vector<vector<int>> printFromTopToBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode* >q;
        q.push(root);q.push(nullptr);
        vector<int> level;
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(!t){
                if(level.empty()) break;
                res.push_back(level);
                level.clear();
                q.push(nullptr);
                continue;
            }
            level.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return res;
    }
};