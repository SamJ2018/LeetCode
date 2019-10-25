/*
A group of cows grabbed a truck and ventured on an expedition deep into the jungle. 
Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank.
The truck now leaks one unit of fuel every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. 
On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).
The jungle is a dangerous place for humans and is especially dangerous for cows. 
Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town.
Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. 
The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.
Input

* Line 1: A single integer, N

* Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.

* Line N+2: Two space-separated integers, L and P
Output

* Line 1: A single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.
Sample Input

4
4 4
5 2
11 5
15 10
25 10
Sample Output

2


��֪һ����·�ϣ���һ�������һ���յ㣬��֮����n������վ����֪����n������վ���յ�ľ���d���������վ���Լ��͵���l�����λ�����յ�ľ���L����
ʼʱ��������������P������ʹ��1����λ�����ͼ���1����λ�ľ��룬����û�����ޣ� ���ټӼ����ͣ����Դ���㿪���յ�?(����޷������յ㣬����-1)
*/