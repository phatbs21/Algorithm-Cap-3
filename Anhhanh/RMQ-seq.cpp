#include <bits/stdc++.h>
using namespace std;
#define mask(i) (1LL << (i))
template <class X, class Y>
bool minimize(X &x, Y y)
{
    if (x > y)
    {
        x = y;
        return false;
    }
    return true;
}
bool getMid(int x, int y)
{
    return x + (y - x) / 2;
}
vector<int> a, tree;
int RMQ(int id, int l, int r, int u, int v)
{
    if (u > r || v < l)
    {
        return INT_MAX;
    }
    if (l >= u && v >= r)
    {
        return tree[id];
    }
    int mid = (l + r) / 2;
    return min(RMQ(2 * id, l, mid, u, v), RMQ(2 * id + 1, mid + 1, r, u, v));
}
void buildTree(int id, int l, int r)
{
    if (l == r)
        tree[id] == a[l];
    int m = (l + r) / 2;
    buildTree(2 * id, l, m);
    buildTree(2 * id + 1, m + 1, r);
    tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}
void xayMang(int n)
{
    int x = 31 - __builtin_clz(n);
    int max_size = 2 * mask(x) + 5;
    tree.resize(max_size);
    buildTree(0, 0, n - 1);
}
int main()
{
    int n, t;
    cin >> n >> t;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    xayMang(n);
    for (int i = 0; i < t; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << RMQ(0, 0, n - 1, u, v);
    }
}