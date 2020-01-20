/*
    ÿ��Ѱ����̱�  �ұ����·����>���ϱ�Ȧ
    �洢�ṹ��ʹ�ñ߼����飬��Ϊÿ��Ѱ����С����������

    e[i] = {u v w}   -> �����ȼ�w��С��������
    ���Ϻ���ͬ-> �ϲ� 
    ϡ��ͼ��kruskal   ����ͼ prim
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int nodeset[N]; //���Ϻ�
int n, m;       //�������ͱ���

struct Edge
{
    int u, v, w;
} e[N * N];

bool cmp(Edge x, Edge y) //�������ȼ� ԽСԽ��
{
    return x.w < y.w;
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
        nodeset[i] = i;
}

//�ϲ�����
int merge(int a, int b)
{
    int p = nodeset[a], q = nodeset[b];
    if (p == q)
        return 0;                //���Ϻ���ͬ�����ܺϲ��������л�
    for (int i = 1; i <= n; i++) //������еĵ㣬����p��ͬ�ļ��Ϻ�q��Ϊp
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
    cout << "��������n�ͱ���m:" << endl;
    cin >> n >> m;
    init(n);
    cout << "��������u,v�ͱ�ֵw" << endl;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e + m, cmp);
    int ans = kruskal(n);

    cout << "��С�Ļ����ǣ�" << ans << endl;
    return 0;
}
