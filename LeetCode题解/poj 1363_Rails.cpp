#include "util.h"
/*
Description

There is a famous railway station in PopPush City. Country there is incredibly hilly. 
The station was built in last century. Unfortunately, funds were extremely limited that time. 
It was possible to establish only a surface track. Moreover, it turned out that the station could be only a dead-end one (see picture) and due to lack of available space it could have only one track.
The local tradition is that every train arriving from the direction A continues in the direction B with coaches reorganized in some way. 
Assume that the train arriving from the direction A has N <= 1000 coaches numbered in increasing order 1, 2, ..., 
N. The chief for train reorganizations must know whether it is possible to marshal coaches continuing in the direction B so that their order will be a1, a2, ..., aN. Help him and write a program that decides whether it is possible to get the required order of coaches. 
You can assume that single coaches can be disconnected from the train before they enter the station and that they can move themselves until they are on the track in the direction B. You can also suppose that at any time there can be located as many coaches as necessary in the station. But once a coach has entered the station it cannot return to the track in the direction A and also once it has left the station in the direction B it cannot return back to the station.

Input

The input consists of blocks of lines. Each block except the last describes one train and possibly more requirements for its reorganization. In the first line of the block there is the integer N described above. In each of the next lines of the block there is a permutation of 1, 2, ..., N. The last line of the block contains just 0.

The last block consists of just one line containing 0.
Output

The output contains the lines corresponding to the lines with permutations in the input. A line of the output contains Yes if it is possible to marshal the coaches in the order required on the corresponding line of the input. Otherwise it contains No. In addition, there is one empty line after the lines corresponding to one block of the input. There is no line in the output corresponding to the last ``null'' block of the input.
Sample Input

5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
Sample Output

Yes
No

Yes
*/

#include <stack>
#include <queue>

/*使用一个队列和栈模拟入栈出栈过程，用以检查序列是否合法*/
bool checkValidOrder(std::queue<int>& order)	//检查序列，存储在队列当中
{
	std::stack<int> S;   //S为模拟栈
	int n = order.size();   //n为序列长度，将1-n按顺序入栈
	for (int i = 1; i <= n; i++)
	{
		S.push(i);    //判断从1-n序列
		while (!S.empty() && order.front() == S.top())  //如果栈不空，并且匹配
		{
			S.pop();
			order.pop();
		}
	}//for

	if (!S.empty()) //栈不空，就返回false,说明不匹配
	{
		return false;
	}
	
	return true;
}//O(n)，实际上while和for“并行”运行

#if 0
int main()
{
	int n;
	int train;
	scanf("%d", &train);
	while (train) {
		std::queue<int> order;
		order.push(train);
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &train);
		}

		if (checkValidOrder(order))
			printf("yes\n");
		else
			printf("No\n");

		scanf("%d", &train);
		
		printf("\n");
		scanf("%d", &n);
	}

	return 0;
}

#endif