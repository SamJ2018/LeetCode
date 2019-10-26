/*
给定一个链表，若其中包含环，则输出环的入口节点。

若其中不包含环，则输出null。

样例

给定如上所示的链表：
[1, 2, 3, 4, 5, 6]
2
注意，这里的2表示编号是2的节点，节点编号从0开始。所以编号是2的节点就是val等于3的节点。

则输出环的入口节点3.

-----------------------------------
算法
(链表，快慢指针扫描) O(n)
本题的做法比较巧妙。
用两个指针 first,second分别从起点开始走，first 每次走一步，second 每次走两步。
如果过程中 second 走到null，则说明不存在环。否则当 first 和 second 相遇后，让 first 返回起点，second 待在原地不动，然后两个指针每次分别走一步，当相遇时，相遇点就是环的入口。



证明：如上图所示，a是起点，b 是环的入口，c 是两个指针的第一次相遇点，ab 之间的距离是 xx，bcbc 之间的距离是 yy。
则当 first 走到 bb 时，由于 secondsecond 比 firstfirst 多走一倍的路，所以 secondsecond 已经从 bb 开始在环上走了 x 步，可能多余1圈，距离 b 还差 y 步（这是因为第一次相遇点在 b 之后 y 步，我们让 first 退回 b 点，则 second 会退 2y 步，也就是距离 b 点还差 y 步）；所以 second 从 b 点走 x+y 步即可回到 b 点，所以 second 从 c 点开始走，走 x 步即可恰好走到 b 点，同时让 first 从头开始走，走 x 步也恰好可以走到 b 点。所以第二次相遇点就是 b 点。

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