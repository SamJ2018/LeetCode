/*
给定一个数字，我们按照如下规则把它翻译为字符串：

0翻译成”a”，1翻译成”b”，……，11翻译成”l”，……，25翻译成”z”。

一个数字可能有多个翻译。例如12258有5种不同的翻译，它们分别是”bccfi”、”bwfi”、”bczi”、”mcfi”和”mzi”。

请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

样例
输入："12258"

输出：5

-------------------------
dp问题：  套路
1、状态表示
    f[i]  前i位有多少种不同的表示？   f[i] = f[i-1] +  f[i-2]  加法原理，确定了第i位只能表示一个字母，则只需要确定f[i-1]，确定i-1和i表示一个字母，只需要确定f[i-2]      
2、状态如何计算
    0~25  
3、边界
*/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int getTranslationCount(string s)
    {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1; //边界
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1];
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (t >= 10 && t <= 25) //满足转移条件
                f[i] += f[i - 2];
        }
        return f[n];
    }
};