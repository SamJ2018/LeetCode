/*
����һ�������ͷ��㣬���� ��β��ͷ ��˳�򷵻ؽڵ��ֵ��

���صĽ��������洢��

����
���룺[2, 3, 5]
���أ�[5, 3, 2]

----------------------------------------------------
�㷨
(��������) O(n)
������ֻ�ܴ�ǰ������������ܴӺ���ǰ������

��������ȴ�ǰ�������һ������������������¼�ڴ������С�
����ٽ��õ����������򼴿ɡ�

ʱ�临�Ӷȷ���
����ʹ�������������˳����Σ�������ʱ�临�Ӷ��� O(n)��
*/
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> printListReversingly(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        return vector<int>(res.rbegin(), res.rend());
    }

    vector<int> printListReversingly2(ListNode *head)
    {
        if (head != NULL)
        {
            if (head->next != NULL)
            {
                printListReversingly(head->next);
            }
            res.push_back(head->val);
        }
        return res;
    }

    vector<int> printListReversingly3(ListNode *head)
    {
        vector<int> res;
        stack<int> stk;
        ListNode *p = head;
        while (p != NULL)
        {
            stk.push(p->val);
            p = p->next;
        }
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }

private:
    vector<int> res;
};