/*
链式前向星 模板   
*/
using namespace std;
#include <iostream>
#include <string.h>
const int maxn = 505, maxe = 100001; //超过矩阵n * n
int n, m, cnt;

int head[maxn]; //头结点数组

struct Node
{
    int to, next, w; //to邻接的边，next下一个邻接边， w权值
} edge[maxe];

void add(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void print()
{
    for (int u = 1; u <= n; u++)
    {
        cout << u << " ";
        for (int i = head[u]; i != -1; i = edge[i].next)
            cout << "----" << i << ":(" << edge[i].to << " " << edge[i].w << " " << edge[i].next << ")";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    cnt = 0;
    memset(head, -1, sizeof(head)); //将head数组全部初始化为-1

    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w); //无向图两条边
        add(v, u, w);
    }
    print();
    return 0;
}
