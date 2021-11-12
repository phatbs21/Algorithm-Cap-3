#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll long long int
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
struct SegmentTree
{
    int64_t n, m;
    vector<int64_t> a, f;
    vector<int64_t> tree;
    vector<int64_t> lazy;
    SegmentTree(int _n)
    {
        n = _n;
        a.assign(n + 1, 0);
        a.assign(n + 2, 0);
        tree.assign(4 * n + 4, 0);
        lazy.assign(4 * n + 4, 0);
    }
    void pushDown(int64_t i, int64_t l, int64_t r)
    {
        if (lazy[i] > 0)
        {
            tree[i] += lazy[i];
            if (l != r)
            {
                lazy[2 * i] += lazy[i];
                lazy[2 * i + 1] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    void build(long long int i, long long int l, long long int r)
    {
        if (l == r)
        {
            tree[i] = a[l];
            return;
        }
        long long int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = max(tree[i * 2], tree[2 * i + 1]);
    }
    void update(int64_t i, int64_t l, int64_t r, int64_t u, int64_t v, int64_t k)
    {
        pushDown(i, l, r);
        if (l > r || l > v || r < u)
            return;
        if (v >= l && r >= u)
        {
            tree[i] += k;
            if (u != v)
            {
                lazy[2 * i] += k;
                lazy[2 * i + 1] += k;
            }
            return;
        }
        int64_t m = (l + r) / 2;
        update(2 * i, l, m, u, v, k);
        update(2 * i + 1, m + 1, r, u, v, k);
        tree[i] = max(tree[2 * i], tree[i * 2 + 1]);
    }
    void update(int64_t u, int64_t v, int64_t k)
    {
        update(1, 1, n, u, v, k);
        return;
    }
    int64_t get_max(int64_t i, int64_t l, int64_t r, int64_t u, int64_t v)
    {
        if (l > v || r < u)
        {
            return INT_MIN;
        }
        pushDown(i, l, r);
        if (l >= u && r <= v)
            return tree[i];
        int64_t m = (l + r) / 2;
        return max(get_max(2 * i, l, m, u, v), get_max(2 * i + 1, m + 1, r, u, v));
    }
    int64_t get_max(int64_t u, int64_t v)
    {
        return get_max(1, 1, n, u, v);
    }
    void printTree()
    {
        for (int i = 1; i <= 4 * n; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    int n, m, c;
    cin >> n >> m >> c;
    SegmentTree tree(n);
    tree.a[0] = c;
    for (int i = 1; i <= m; i++)
    {
        int l, r, temp;
        cin >> l >> r >> temp;
        //tree.update(l, r, c);
        tree.f[l] += temp, tree.f[r + 1] -= temp;
    }
    for (int i = 1; i <= n; i++)
    {
        tree.a[i] = tree.a[i - 1] + tree.f[i]; 
        cout << tree.a[i] << " ";
    }
    cout << endl;
    tree.build(1, 1, n);
    int q;
    cin >> q;
    //tree.printTree();
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        // cout << l << " " << r << "\n";
        tree.update(l, r, 1);
        cout << tree.get_max(l, r) << "\n";
    }
}
