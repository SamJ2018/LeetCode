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


��֪һЩ���Ӻ�һЩ�ǹ���ÿ����������������g��ÿ���ǹ��д�Сs����ĳ���ǹ��Ĵ�Сs >= ĳ�����ӵ���������gʱ��������ǹ���������ú��ӣ���ʹ����Щ�ǹ��������������ٺ��ӣ� (ע�⣬ĳ���������ֻ����1���ǹ�����)
���磬������������g = [5, 10, 2, 9, 15, 9]���ǹ���С����s = [6, 1, 20, 3, 8]�� ����������3�����ӡ�

���壺
���磬������������ g = [5, 10, 2, 9, 15, 9]���ǹ���С���� s = [6, 1, 20, 3, 8]��
Ϊ�˸����Ե��ж�ĳ�����ӿ��Ա�ĳ���ǹ����㣬��g, s���������۲�:
g = [2, 5, 9, 9, 10, 15]�� s = [1, 3, 6, 8, 20]��
1.�Ƿ����ֱ�ӱ���ö�٣���ÿ���ǹ��������Ƿ��������ĳ������?
2.��ĳ�����ӿ��Ա�����ǹ�����ʱ���Ƿ���Ҫ������ĳ���ǹ������������?
3.��ĳ���ǹ���������������ʱ���Ƿ���Ҫ��������ĳ������?

˼·
1.��������������g���ǹ���С����s���д�С���������
2.���մ�С�����˳��ʹ�ø��ǹ������Ƿ������ĳ�����ӣ�ÿ���ǹ�ֻ����1�Σ������Գɹ�������һ�����ӳ��ԣ�ֱ������û����ĺ��ӻ���û������ǹ���ѭ��������
*/
#include "util.h"

class Solution
{
public:
	int findContentChildren(vector<int>& g, vector<int>& s) //��������g��ͨ����Сs
	{
		sort(g.begin(), g.end()); //�ȶԺ��ӵ���������g���ǹ���Сs��������
		sort(s.begin(), s.end());
		int child = 0, cookie = 0; //child:�����˼�������  cookie�����˼����ǹ�

		while (child < g.size() && cookie < s.size())//���ӻ��ǹ�ͬʱ��δ������
		{
			if (g[child] <= s[cookie])//���ӵ���������С�ڵ����ǹ���С
			{
				child++;  //����ָ����ƣ������ж�
			}
			cookie++;   //����ʧ�����ÿ���ǹ�ֻ����һ�Σ�cookies����ƶ�
		}
		return child;   //���յ�child�������㺢�ӵĸ���
	}
};