#include <bits/stdc++.h>
// thuy duong is my love
using namespace std;
int64_t n, m;
vector<int64_t> tree;
vector<int64_t> lazy;
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
void update(int64_t i, int64_t l, int64_t r, int64_t u, int64_t v, int64_t k)
{
    pushDown(i, l, r);
    if (l > r || l > v || r < u)
        return;
    if (u <= l && v >= r)
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
    if (l > r || l > v || r < u)
        return INT_MIN;
    pushDown(i, l, r);
    if (u <= l && r <= v)
    {
        return tree[i];
    }
    int64_t m = (l + r) / 2;
    return max(get_max(2 * i, l, m, u, v), get_max(2 * i + 1, m + 1, r, u, v));
}
int64_t get_max(int64_t u, int64_t v)
{
    return get_max(1, 1, n, u, v);
}
int main()
{
    freopen("QMAX2.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    tree.assign(300000, 0);
    lazy.assign(300000, 0);
    while (m--)
    {
        int64_t temp, l, r, k;
        cin >> temp >> l >> r;
        if (temp == 0)
        {
            cin >> k;
            update(l, r, k);
        }
        else
            cout << get_max(l, r) << "\n";
    }
    // for (int64_t i = 1; i <= 4 * n; i++)
    //     cout << lazy[i] << " ";
}