#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
struct inppuQ
{
    int i, j, k, id;
};
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.fi > b.fi)
        return true;
    else
        return false;
}
bool comp2(const inppuQ &a, const inppuQ &b)
{
    if (a.k > b.k)
        return false;
    return true;
}
int n;
vector<int> tree;
vector<int> lazy;
pair<int, int> a[300005 + 1];
int ans[300005 + 1];
void down(int i, int l, int r) // lazy update
{
    int m = (l + r) / 2;
    tree[2 * i] = (tree[2 * i] + lazy[i] * (m - l + 1));
    tree[2 * i + 1] = (tree[2 * i] + lazy[i] * (r - m));
    lazy[2 * i] = (lazy[2 * i] + lazy[i]);
    lazy[2 * i + 1] = lazy[2 * i + 1] + lazy[i];
}
void update(int i, int l, int r, int p, int k)
{
    if (p < l or p > r)
    {
        return;
    }
    if (l == r)
    {
        tree[i] = 0;
        return;
    }
    int m = l + r;
    update(2 * i, l, m, p, k);
    update(2 * i + 1, m + 1, r, p, k);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int get_sum(int i, int l, int r, int u, int v)
{
    if (v < l || u > r)
        return 0;
    if (u <= l && r <= v)
    {
        return tree[i];
    }
    int m = (l + r) / 2;
    return get_sum(2 * i, l, m, u, v) + get_sum(2 * i + 1, m + 1, r, u, v);
}
int get(int u, int v)
{
    return get_sum(1, 1, n, u, v);
}
int binarySearch(int l, int r, int k)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid].fi >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    freopen("KQUERY.inp", "r", stdin);
    cin >> n;
    tree.resize(4 * n + 4, 0);
    lazy.resize(4 * n + 4, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1, comp);
    int qs;
    cin >> qs;
    inppuQ q[qs + 1];
    for (int w = 1; w <= qs; w++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        q[w].i = i, q[w].j = j, q[w].k = k;
        q[w].id = i;
    }
    sort(q + 1, q + qs + 1, comp2);
    int vt = 1;
    for (int i = 1; i <= qs; i++)
    {
        int l = q[i].i, r = q[i].j, k = q[i].k, p = q[i].id;
        int now = binarySearch(l, r, k + 1);
        for (int j = vt; j < now; j++)
            update(1, 1, n, a[i].se, -1);
        vt = now;
        ans[p] = get(l, r);
    }
    for (int i = 1; i <= qs; i++)
    {
        cout << ans[i] << endl;
    }
}