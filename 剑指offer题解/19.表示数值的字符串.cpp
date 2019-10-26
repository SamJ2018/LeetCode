/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。

但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

注意:

小数可以没有整数部分，例如.123等于0.123；
小数点后面可以没有数字，例如233.等于233.0；
小数点前面和后面可以有数字，例如233.666;
当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4;
样例：
输入: "0"

输出: true
-----------------------------------------------------------
算法
(模拟，字符串处理) O(n)
先去除行首和行尾空格；
行首如果有一个正负号，直接忽略；
如果字符串为空或只有一个'.'，则不是一个合法数；
循环整个字符串，去掉以下几种情况：
(1) '.'或'e'多于1个;
(2) '.'在'e'后面出现；
(3) 'e'后面或前面为空，或者'e'前面紧跟着'.'；
(4) 'e'后面紧跟着正负号，但正负号后面为空；
剩下的情况都合法；
时间复杂度分析：整个字符串只遍历一遍，所以时间复杂度是 O(n)。
*/
#include <cstring>
#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int i = 0, j = s.size();
        while (i <= j && s[i] == ' ')
            ++i;
        while (i <= j && s[j] == ' ')
            --j;
        if (i > j)
            return false;
        s = s.substr(i, j - i + 1);
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        if (s.empty() || s[0] == '.' && s.size() == 1)
            return false; //去掉+,-,.

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                ;
            else if (s[i] == '.')
            {
                dot++;
                if (dot > 1 || e)
                    return false; //xxxxx.xxxxx.xxxxx    xxxxexxxx.xxxx
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                e++;
                if (!i || i + 1 == s.size() || e > 1 || s[i - 1] == '.' && i == 1)
                    return false; //exxxx  ,xxxxe, xxxexxxx
                if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    if (i + 2 == s.size())
                        return false; //xxxe+
                    i++;
                }
            }
            else
                return false;
        }
        return true;
    }
};

class Solution2
{
public:
    bool isNumeric(char *str)
    {
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == 'e' || str[i] == 'E')
            {
                if (i == strlen(str) - 1)
                    return false; // e后面一定要接数字
                if (hasE)
                    return false; // 不能同时存在两个e
                hasE = true;
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                // 第二次出现+-符号，则必须紧接在e之后
                if (sign && str[i - 1] != 'e' && str[i - 1] != 'E')
                    return false;
                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
                    return false;
                sign = true;
            }
            else if (str[i] == '.')
            {
                // e后面不能接小数点，小数点不能出现两次
                if (hasE || decimal)
                    return false;
                decimal = true;
            }
            else if (str[i] < '0' || str[i] > '9') // 不合法字符
                return false;
        }
        return true;
    }
};