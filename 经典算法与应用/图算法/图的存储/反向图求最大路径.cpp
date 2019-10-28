/*
给出N个点，M条边的有向图，对于每个点v，求A(v)表示从点v出发，能到达的编号最大的点。

思路：
实际上就是从v点出发能遍历到的最大点，可以采用两种思路：
深度优先遍历去遍历所有的点求最大值；
也可以换个思路，建立原图的反向图，从最大点v出发，凡是能遍历到的点w，w能到达的最大点就是v
*/
#include <iostream>
using namespace std;

const int maxn = 100000 + 5;
int maxx[maxn], head[maxn], nex[maxn], to[maxn]; //to 能到达的邻接点
int n, m, x, y, total;

//添加一条 u--v的边
void add(int u, int v)
{
    nex[++total] = head[u];
    head[u] = total;
    to[total] = v;
}

void dfs(int u, int v)
{
    if (maxx[u])
        return;
    maxx[u] = v; //找到访问的最大点，让他等于v

    for (register int e = head[u]; e; e = nex[e])
        if (!maxx[to[e]])
            dfs(to[e], v); //让所有的点最大点都是v
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        add(y, x); //创建反向图
    }
    for (int i = n; i; i--)
        dfs(i, i);

    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            cout << " ";
        cout << maxx[i];
    }
    return 0;
}