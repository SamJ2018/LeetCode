/*
    prim   ���ϱ�Ȧ   V����  V-U����
*/
#include <iostream>
using namespace std;

const int INF = 0x3fffffff;
const int N = 100;

bool s[N]; //�ж�����S ����V-S����
int closest[N];
int lowcost[N];

/*
ʹ���ڽӾ���������
n -- ����ĸ���
u -- ��ʼ����
c[N][N] -- ��Ȩ�ڽӾ���
s[i]   ���s[i]=true ˵������i�Ѿ����뵽����С��������
       ���򶥵�i���ڼ���V-U��
�������ص���СȨֵ���ݵ�����lowcost��
*/
void prim(int n, int u, int c[N][N])
{
    s[u] = true; //��ʼ��ʱ�򣬼���U��ֻ��һ��Ԫ�أ�������u
    int i, j;
    //��ʼ��s[] lowcost[] closest[]
    for (i = 1; i <= n; i++)
    {
        if (i != u)
        {
            lowcost[i] = c[u][i]; //���붥��u�ڽӵĵ��Ȩֵ���뵽lowcost������
            closest[i] = u;
            s[i] = false; //
        }
        else
            lowcost[i] = 0;
    }

    for (i = 1; i <= n; i++) //�ڼ���V-U��Ѱ�Ҿ��뼯��U����Ķ���t
    {
        int temp = INF, t = u;
        for (j = 1; j <= n; j++)
            if (!s[j] && lowcost[j] < temp) //�������j����V-U ����ȨֵС����U���ڽӵ�Ȩֵ
                t = j, temp = lowcost[j];
        if (t == u)
            break;               //�Ҳ�������Ķ���t������ѭ��
        s[t] = true;             //�ҵ�����t���뵽����U��
        for (j = 1; j <= n; j++) //����lowcost��closest
        {
            if (!s[j] && c[t][j] < lowcost[j]) //�ڼ���v-u��Ѱ�ң���t�ڽӲ���С�ڵ�ǰ��Ȩֵ
            {
                lowcost[j] = c[t][j];
                closest[j] = t;
            }
        }
    }
} //O(n^2)

int main()
{
    int n, c[N][N], m, u, v, w; //���������ڽӾ��󡢱����������u���ڽӵ�v��Ȩֵw
    int u0;                     //Դ��
    cout << "���������ͱ���m��" << endl;
    cin >> n >> m;
    int sumcost = 0; //��СȨֵ

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = INF;
    cout << "��������u��v�ͱ�ֵw��" << endl;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        c[u][v] = c[v][u] = w;
    }

    cout << "������һ���u0:" << endl;
    cin >> u0;

    prim(n, u0, c);
    cout << "����lowcost������Ϊ" << endl;
    for (int i = 1; i <= n; i++)
        cout << lowcost[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        sumcost += lowcost[i];
    cout << "��С�Ļ����ǣ�" << sumcost << endl;

    return 0;
}