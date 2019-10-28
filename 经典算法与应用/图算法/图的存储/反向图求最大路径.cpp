/*
����N���㣬M���ߵ�����ͼ������ÿ����v����A(v)��ʾ�ӵ�v�������ܵ���ı�����ĵ㡣

˼·��
ʵ���Ͼ��Ǵ�v������ܱ����������㣬���Բ�������˼·��
������ȱ���ȥ�������еĵ������ֵ��
Ҳ���Ի���˼·������ԭͼ�ķ���ͼ��������v�����������ܱ������ĵ�w��w�ܵ�����������v
*/
#include <iostream>
using namespace std;

const int maxn = 100000 + 5;
int maxx[maxn], head[maxn], nex[maxn], to[maxn]; //to �ܵ�����ڽӵ�
int n, m, x, y, total;

//���һ�� u--v�ı�
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
    maxx[u] = v; //�ҵ����ʵ����㣬��������v

    for (register int e = head[u]; e; e = nex[e])
        if (!maxx[to[e]])
            dfs(to[e], v); //�����еĵ����㶼��v
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        add(y, x); //��������ͼ
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