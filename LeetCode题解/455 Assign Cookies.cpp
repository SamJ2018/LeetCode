/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. 
Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.


已知一些孩子和一些糖果，每个孩子有需求因子g，每个糖果有大小s，当某个糖果的大小s >= 某个孩子的需求因子g时，代表该糖果可以满足该孩子；求使用这些糖果，最多能满足多少孩子？ (注意，某个孩子最多只能用1个糖果满足)
例如，需求因子数组g = [5, 10, 2, 9, 15, 9]；糖果大小数组s = [6, 1, 20, 3, 8]； 最多可以满足3个孩子。

陷阱：
例如，需求因子数组 g = [5, 10, 2, 9, 15, 9]；糖果大小数组 s = [6, 1, 20, 3, 8]。
为了更明显的判断某个孩子可以被某个糖果满足，对g, s进行排序后观察:
g = [2, 5, 9, 9, 10, 15]； s = [1, 3, 6, 8, 20]。
1.是否可以直接暴力枚举，对每个糖果都尝试是否可以满足某个孩子?
2.当某个孩子可以被多个糖果满足时，是否需要优先用某个糖果满足这个孩子?
3.当某个糖果可以满足多个孩子时，是否需要优先满足某个孩子?

思路
1.对需求因子数组g与糖果大小数组s进行从小到大的排序。
2.按照从小到大的顺序使用各糖果尝试是否可满足某个孩子，每个糖果只尝试1次；若尝试成功，则换下一个孩子尝试；直到发现没更多的孩子或者没更多的糖果，循环结束。
*/
#include "util.h"

class Solution
{
public:
	int findContentChildren(vector<int>& g, vector<int>& s) //需求因子g和通过大小s
	{
		sort(g.begin(), g.end()); //先对孩子的需求因子g和糖果大小s数组排序
		sort(s.begin(), s.end());
		int child = 0, cookie = 0; //child:满足了几个孩子  cookie尝试了几个糖果

		while (child < g.size() && cookie < s.size())//孩子或糖果同时均未尝试完
		{
			if (g[child] <= s[cookie])//孩子的需求因子小于等于糖果大小
			{
				child++;  //孩子指针后移，继续判断
			}
			cookie++;   //无论失败与否，每个糖果只尝试一次，cookies向后移动
		}
		return child;   //最终的child就是满足孩子的个数
	}
};