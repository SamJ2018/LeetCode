/*
��ʵ��һ����������֮����˳��������´�ӡ��������

����һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ���������Դ����ơ�

����
��������ͼ��ʾ������[8, 12, 2, null, null, 6, 4, null, null, null, null]
    8
   / \
  12  2
     / \
    6   4
�����[[8], [2, 12], [6, 4]]

---------------------------------
�㷨
(BFS) O(n)
������ȱ�����һ��һ������������

�����ڵ��������У�
����һ���¶��У�������˳�򱣴���һ��������ӽڵ㣻
���ڵ�ǰ�����е����нڵ㣬��˳�����ν����Ӳ����¶��У�
�������ҡ����ҵ����˳���汣������нڵ��ֵ��
�ظ�����2-4��ֱ������Ϊ��Ϊֹ��
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
        bool zigzag=false;
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(!t){
                if(level.empty()) break;
                if(zigzag) reverse(level.begin(),level.end());
                res.push_back(level);
                level.clear();
                q.push(nullptr);
                zigzag=!zigzag;
                continue;
            }
            level.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return res;
    }
};