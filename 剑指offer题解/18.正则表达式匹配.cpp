/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。

模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。

在本题中，匹配是指字符串的所有字符匹配整个模式。

例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。

样例
输入：

s="aa"
p="a*"

输出:true

----------------------------------------------------------------------
算法
(动态规划) O(nm)
状态表示：f[i][j]表示p从j开始到结尾，是否能匹配s从i开始到结尾
状态转移：

如果p[j+1]不是通配符'*'，则f[i][j]是真，当且仅当s[i]可以和p[j]匹配，且f[i+1][j+1]是真；
如果p[j+1]是通配符'*'，则下面的情况只要有一种满足，f[i][j]就是真；
f[i][j+2]是真；
s[i]可以和p[j]匹配，且f[i+1][j]是真；
第1种情况下的状态转移很好理解，那第2种情况下的状态转移怎么理解呢？

最直观的转移方式是这样的：枚举通配符'*'可以匹配多少个p[j]，只要有一种情况可以匹配，则f[i][j]就是真；
这样做的话，我们发现，f[i][j]除了枚举0个p[j]之外，其余的枚举操作都包含在f[i+1][j]中了，所以我们只需判断
f[i+1][j]是否为真，以及s[i]是否可以和p[j]匹配即可。

时间复杂度分析：n 表示s的长度，m 表示p的长度，总共 nm 个状态，状态转移复杂度 O(1)，所以总时间复杂度是 O(nm).
*/
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> f;
    string s, p;

    bool isMatch(string _s, string _p)
    {
        s = _s, p = _p;
        n = s.size(), m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return dp(0, 0);
    }

    bool dp(int x, int y)
    {
        if (f[x][y] != -1)
            return f[x][y];
        if (y == m)
            return f[x][y] = x == n;
        bool first_match = x < n && (p[y] == '.' || s[x] == p[y]);
        if (y + 1 < m && p[y + 1] == '*')
            f[x][y] = dp(x, y + 2) || first_match && dp(x + 1, y); //x+1
        else
            f[x][y] = first_match && dp(x + 1, y + 1);
        return f[x][y];
    }
};

class Solution2
{
public:
    bool match(char *str, char *pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern + 1) != '*')
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str + 1, pattern + 1);
            else
                return false;
        }
        else
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern + 2) || match(str + 1, pattern);
            else
                return match(str, pattern + 2);
        }
    }
};