/*
输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。

例如输入12，从1到12这些整数中包含“1”的数字有1，10，11和12，其中“1”一共出现了5次。

样例
输入： 12
输出： 5

思路：
比如  abcdef 
如果c为1 那么前两位可以从00~ab-1  后三位可以从000~def
如果ab不为1 那么c分为三种情况 若c为0 则0个1   c=1时0~def  c>1  000~999
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int numberOf1Between1AndN_Solution(int n)
    {
        if (!n)
            return 0;
        vector<int> number;
        while (n)
            number.push_back(n % 10), n /= 10; //将每一位取出
        int res = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            auto left = 0, right = 0, t = 1;
            // 相当于求12x34  x的左右 left=12  right=34  t相当于算范围
            for (int j = number.size() - 1; j > i; j--)
                left = left * 10 + number[j];
            for (int j = i - 1; j >= 0; j--)
                right = right * 10 + number[j], t *= 10;
            res += left * t;
            if (number[i] == 1)
                res += right + 1;
            else if (number[i] > 1)
                res += t;
        }
        return res;
    }
};