/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。

例如，当从字符流中只读出前两个字符”go”时，第一个只出现一次的字符是’g’。

当从该字符流中读出前六个字符”google”时，第一个只出现一次的字符是’l’。

如果当前字符流没有存在出现一次的字符，返回#字符。

样例
输入："google"

输出："ggg#ll"

解释：每当字符流读入一个字符，就进行一次判断并输出当前的第一个只出现一次的字符。
---------------------------
双指针or单调队列

*/
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    unordered_map<char, int> count;
    queue<int> q;
    //Insert one char from stringstream
    void insert(char ch)
    {
        if (++count[ch] > 1)
            while (q.size() && count[q.front()] > 1)
                q.pop();
        else
            q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce()
    {
        if (q.empty())
            return '#';
        return q.front();
    }
};