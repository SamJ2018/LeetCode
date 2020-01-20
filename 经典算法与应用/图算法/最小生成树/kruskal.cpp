/*
    每次寻找最短边  且避免回路——>集合闭圈
    存储结构：使用边集数组，因为每次寻找最小，进行排序

    e[i] = {u v w}   -> 按优先级w从小到大排序
    集合号相同-> 合并 
    稀疏图用kruskal   稠密图 prim
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int nodeset[N]; //集合号
int n, m;       //顶点数和边数

struct Edge
{
    int u, v, w;
} e[N * N];

bool cmp(Edge x, Edge y) //定义优先级 越小越好
{
    return x.w < y.w;
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
        nodeset[i] = i;
}

//合并操作
int merge(int a, int b)
{
    int p = nodeset[a], q = nodeset[b];
    if (p == q)
        return 0;                //集合号相同，不能合并，否则有环
    for (int i = 1; i <= n; i++) //检查所有的点，把与p不同的集合号q改为p
        if (nodeset[i] == q)
            nodeset[i] = p;
    return 1;
}

int kruskal(int n)
{
    int ans = 0;
    for (int i = 0; i < m; i++)
        if (merge(e[i].u, e[i].v))
        {
            ans += e[i].w;
            if (n-- == 1)
                return ans;
        }
    return 0;
} //tc O(E)

int main()
{
    cout << "输入结点数n和边数m:" << endl;
    cin >> n >> m;
    init(n);
    cout << "输入结点数u,v和边值w" << endl;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e + m, cmp);
    int ans = kruskal(n);

    cout << "最小的花费是：" << ans << endl;
    return 0;
}
