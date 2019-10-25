#include "util.h"
/*
有1元、 2元、 5元、 10元、 20元、 50元、 100元的钞票无穷多张。现使用这
些钞票支付X元， 最少需要多少张?
例如， X = 628
最佳支付方法:
6张100块的， 1张20块的， 1张5块的， 1张2块的， 1张1块的；
共需要6+1+1+1+1=10张。
直觉告诉我们:尽可能多的使用面值较大的钞票！
贪心法: 遵循某种规律，不断贪心的选取当前最优策略的算法设计方法。


为何这么做一定是对的?
面额为1元、 2元、 5元、 10元、 20元、 50元、 100元，每个面额是比自己小的面
额的2倍或以上。
所以当使用一张较大面额钞票时，若用较小面额钞票替换，需要两张
或更多的钞票！
例如:
2 = 1 + 1
5 = 2 + 2 + 1
10 = 5 + 5
20 = 10 + 10
50 = 20 + 20 + 10
100 = 50 + 50
故， 当前最优解即为全局最优解，贪心成立！
思考: 如果增加7元面额，贪心还成立吗?
*/

int main_greedy()
{
	const int RMB[] = { 100,50,20,10,5,2,1 }; //人名币面额
	const int NUM = 7;  //7种面额

	int X = 628; //用RMB最少多少张，组成X
	int count = 0;

	for (int i = 0; i < NUM; i++)
	{
		int use = X / RMB[i];  //需要面额为RMB[i]的use张
		count += use;          //总计增加use张
		X -= RMB[i] * use;     //将总额减去使用RMB[i]已组成的金额

		printf("需要面额为%d的%d张", RMB[i], use);
		printf("剩余需要支付RMB %d.\n", X);
	}

	printf("总共需要%d张RMB\n", count);
	return 0;
}