/*

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。

假设压入栈的所有数字均不相等。

例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。

注意：若两个序列长度不等则视为并不是一个栈的压入、弹出序列。若两个序列都为空，则视为是一个栈的压入、弹出序列。

样例
输入：[1,2,3,4,5]
      [4,5,3,2,1]

输出：true

------------------------------------------
算法1
(栈) O(n)
用一个新栈s来模拟实时进出栈操作：

在for loop里依次喂数，每push一个数字就检查有没有能pop出来的。

如果最后s为空（或者popId==popV.size())，说明一进一出刚刚好。

时间复杂度分析：一共push n次，pop n次。
*/

#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return pushV.empty() && popV.empty(); //
        stack<int> s;
        int popId = 0;
        for (int pushId = 0; pushId < pushV.size(); ++pushId)
        {
            s.push(pushV[pushId]);
            while (!s.empty() && s.top() == popV[popId])
            {
                s.pop();
                ++popId;
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};