/*
在字符串中找出第一个只出现一次的字符。

如输入"abaccdeff"，则输出b。

如果字符串中不存在只出现一次的字符，返回#字符。

样例：
输入："abaccdeff"

输出：'b'
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char firstNotRepeatingChar(string s)
    {
        unordered_map<char, int> count;
        for (auto c : s)
            count[c]++;
        char res = '#';
        for (auto c : s)
            if (count[c] == 1)
            {
                res = c;
                break;
            }
        return res;
    }
};