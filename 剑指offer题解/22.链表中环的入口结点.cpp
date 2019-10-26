/*
����һ�����������а������������������ڽڵ㡣

�����в��������������null��

����

����������ʾ������
[1, 2, 3, 4, 5, 6]
2
ע�⣬�����2��ʾ�����2�Ľڵ㣬�ڵ��Ŵ�0��ʼ�����Ա����2�Ľڵ����val����3�Ľڵ㡣

�����������ڽڵ�3.

-----------------------------------
�㷨
(��������ָ��ɨ��) O(n)
����������Ƚ����
������ָ�� first,second�ֱ����㿪ʼ�ߣ�first ÿ����һ����second ÿ����������
��������� second �ߵ�null����˵�������ڻ������� first �� second �������� first ������㣬second ����ԭ�ز�����Ȼ������ָ��ÿ�ηֱ���һ����������ʱ����������ǻ�����ڡ�



֤��������ͼ��ʾ��a����㣬b �ǻ�����ڣ�c ������ָ��ĵ�һ�������㣬ab ֮��ľ����� xx��bcbc ֮��ľ����� yy��
�� first �ߵ� bb ʱ������ secondsecond �� firstfirst ����һ����·������ secondsecond �Ѿ��� bb ��ʼ�ڻ������� x �������ܶ���1Ȧ������ b ���� y ����������Ϊ��һ���������� b ֮�� y ���������� first �˻� b �㣬�� second ���� 2y ����Ҳ���Ǿ��� b �㻹�� y ���������� second �� b ���� x+y �����ɻص� b �㣬���� second �� c �㿪ʼ�ߣ��� x ������ǡ���ߵ� b �㣬ͬʱ�� first ��ͷ��ʼ�ߣ��� x ��Ҳǡ�ÿ����ߵ� b �㡣���Եڶ������������ b �㡣

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *entryNodeOfLoop(ListNode *head)
    {
        auto slow = head, fast = head;
        while (slow && fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else
                return 0;
            if (fast == slow)
            {
                slow = head;
                while (fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return 0;
    }
};