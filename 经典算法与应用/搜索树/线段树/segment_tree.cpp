#include <stdio.h>
#include <cstring>
#define MAX_LEN 1000

void build_tree(int arr[], int tree[], int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    //取中值
    else
    {
        int mid = (start + end) >> 1;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(arr, tree, left_node, start, mid);
        build_tree(arr, tree, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}
//将arr[idx]=val
void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val)
{
    if (start == end)
        arr[idx] = val, tree[node] = val;
    else
    {
        int mid = (start + end) >> 1;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        if (idx >= start && idx <= mid)
            update_tree(arr, tree, left_node, start, mid, idx, val);
        else
            update_tree(arr, tree, right_node, mid + 1, end, idx, val);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R)
{
    printf("start=%d\n", start);
    printf("end=%d\n", end);

    if (R < start || L > end) //没有交集
        return 0;
    else if (L <= start && end <= R) //防止重复计算
        return tree[node];
    else if (start == end)
        return tree[node];
    else
    {
        int mid = (start + end) >> 1;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left = query_tree(arr, tree, left_node, start, mid, L, R);
        int sum_right = query_tree(arr, tree, right_node, mid + 1, end, L, R);
        return sum_left + sum_right;
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int tree[MAX_LEN] = {0};
    build_tree(arr, tree, 0, 0, 5);
    for (int i = 0; i < 15; i++)
        printf("tree[%d]=%d\n", i, tree[i]);

    update_tree(arr, tree, 0, 0, 5, 4, 6);
    for (int i = 0; i < 15; i++)
        printf("tree[%d]=%d\n", i, tree[i]);
    int s = query_tree(arr, tree, 0, 0, 5, 2, 5);
    printf("s=%d\n", s);
    return 0;
}