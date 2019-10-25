/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


已知一个使用字符串表示的非负整数num，将num中的k个数字移除，求移除k个数字后，可以获得的最小的可能的新数字。
输入 : num = “1432219” , k = 3
在去掉3个数字后得到的很多很多可能里，如1432、 4322、 2219、 1219、 1229...；
去掉数字4、 3、 2得到的1219最小！

1.输入的num， 字符串长度<=10002，并且字符串长度>=k
2.输入的num字符串不会以任何数量的0字符开头


思考：
1.当所有数字都扫描完成后， k仍然>0，应该做怎样的处理？
例如: num = 12345， k = 3 时。
2.当数字中有0出现时，应该有怎样的特殊处理？
例如: num = 100200, k = 1 时。
3.如何将最后结果存储为字符串并返回?
*/

#include "util.h"

class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		vector<int> S; //使用vector当作栈，方便遍历最后返回
		string result = ""; //存储最终结果的字符串

		for (int i = 0; i < num.length(); i++)  //从最高位循环扫描数字num
		{
			int number = num[i] - '0';  //将字符型的num转化为整数使用
			while (S.size() != 0 && S[S.size() - 1] > number && k > 0) //当栈不空，栈顶大于number 仍然可以删除数字时继续循环
			{
				S.pop_back();  //弹出栈顶元素
				k--;
			}
			if (number != 0 || S.size() != 0) //确保前缀不为0
			{
				S.push_back(number);  //将数字number压入栈中
			}
		}

		while (S.size() != 0 && k > 0)
		{
			//栈不空，说明均是递增序列 仍然可以删除末尾元素
			S.pop_back();
			k--;   //弹出栈顶并更新k
		}
		
		for (int i = 0; i < S.size(); i++)
		{
			result.append(1, '0' + S[i]); //将栈中的元素从头遍历，存储到result中
		}

		if (result == "") //result为空，则返回0
			result = "0";

		return result;
	}
};