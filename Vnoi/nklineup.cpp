#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
int n, q;
typedef pair<int, int> pii;
vector<int> a;
vector<pair<int, int>> tree;
// first: max
// second: min
void build(int i, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        tree[i].fi = a[l];
        tree[i].se = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i].fi = max(tree[2 * i].fi, tree[2 * i + 1].fi);
    tree[i].se = min(tree[2 * i].se, tree[2 * i + 1].se);
}

pair<int, int> get(int i, int l, int r, int u, int v)
{
    if (l > r || l > v || r < u)
        return mp(INT_MIN, INT_MAX);
    if (l >= u && r <= v)
        return tree[i];
    int m = (l + r) / 2;
    pii ll = get(2 * i, l, m, u, v);
    pii rr = get(2 * i + 1, m + 1, r, u, v);
    return mp(max(ll.fi, rr.fi), min(ll.se, rr.se));
}
void printTree()
{
    for (int i = 1; i <= 4 * n; i++)
        cout << tree[i].first << " ";
    cout << endl;
    for (int i = 1; i <= 4 * n; i++)
        cout << tree[i].se << " ";
    cout << endl;
}
int main()
{
    //freopen("nklineup.inp", "r", stdin);
    cin >> n >> q;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    tree.assign(n * 4 + 4, mp(-1, INT_MAX));
    build(1, 1, n);
    //printTree();
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        pii kq = get(1, 1, n, x, y);
        cout << kq.fi - kq.se << "\n";
    }
}