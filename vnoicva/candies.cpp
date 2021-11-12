#include <bits/stdc++.h>
using namespace std;
vector<int> a, t;
struct segMentTree
{
    vector<int> tree, a;
    int n;
    segMentTree()
    {
        n = 0;
    }
    segMentTree(int _n)
    {
        n = _n;
        tree.assign(n + 4, 0);
        a.assign(n + 1, 0);
    }
    void build(int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    void update(int i, int l, int r, int u, int v,int c)
    {
        if (l > r || r < u || l > v || v < u)
        {
            return;
        }
        if (u <= l && r <= v)
        {
            tree[i] = (tree[i] + c);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("candies.inp", "r", stdin);
    freopen("candies.out", "w", stdout);
#endif
    int n, m;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    t.resize(m + 1);
    for (int j = 1; j <= m; j++)
        cin >> t[j];
    
}