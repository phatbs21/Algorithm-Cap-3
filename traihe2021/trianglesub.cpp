#include <bits/stdc++.h>
using namespace std;
struct segMentTree
{
    vector<int> a;
    vector<pair<int, int>> tree;
    int n;
    segMentTree()
    {
        n = 0;
    }
    segMentTree(int _n)
    {
        n = _n;
        tree.assign(4 * n + 7, {0, 0});
        a.assign(n + 1, 0);
    }
    void build(int i, int l, int r)
    {
        if (r == l)
        {
            tree[i].first = a[l];
            tree[i].second = l;
            return;
        }
        int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);

        if (tree[2 * i].first <= tree[2 * i + 1].first)
        {
            tree[i].first = tree[2 * i].first;
            tree[i].second = tree[2 * i].second;
        }
        else
        {
            tree[i].first = tree[2 * i + 1].first;
            tree[i].second = tree[2 * i + 1].second;
        }
    }
    pair<int, int> get(int i, int l, int r, int u, int v)
    {
        if (r < u || l > v)
        {
            return make_pair(1e9, 0);
        }
        if (l >= u && r <= v)
        {
            return make_pair(tree[i].first, tree[i].second);
        }
        int mid = (l + r) / 2;
        if (get(2 * i, l, mid, u, v).first <= get(2 * i + 1, mid + 1, r, u, v).first)
            return get(2 * i, l, mid, u, v);
        else
            return get(2 * i + 1, mid + 1, r, u, v);
    }
    int get(int l, int r)
    {
        return get(1, 1, n, l, r).second;
    }
};

struct segMentTree2
{
    vector<int> a;
    vector<pair<int, int>> tree;
    int n;
    segMentTree2()
    {
        n = 0;
    }
    segMentTree2(int _n)
    {
        n = _n;
        tree.assign(4 * n + 7, {0, 0});
        a.assign(n + 1, 0);
    }
    void build(int i, int l, int r)
    {
        if (r == l)
        {
            tree[i].first = a[l];
            tree[i].second = l;
            return;
        }
        int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);

        if (tree[2 * i].first >= tree[2 * i + 1].first)
        {
            tree[i].first = tree[2 * i].first;
            tree[i].second = tree[2 * i].second;
        }
        else
        {
            tree[i].first = tree[2 * i + 1].first;
            tree[i].second = tree[2 * i + 1].second;
        }
    }
    pair<int, int> get(int i, int l, int r, int u, int v)
    {
        if (r < u || l > v)
        {
            return make_pair(-1e9, 0);
        }
        if (l >= u && r <= v)
        {
            return make_pair(tree[i].first, tree[i].second);
        }
        int mid = (l + r) / 2;
        if (get(2 * i, l, mid, u, v).first >= get(2 * i + 1, mid + 1, r, u, v).first)
            return get(2 * i, l, mid, u, v);
        else
            return get(2 * i + 1, mid + 1, r, u, v);
    }
    int get(int l, int r)
    {
        return get(1, 1, n, l, r).second;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    segMentTree in(n + 1);
    segMentTree2 ax(n + 1);
    for (int i = 1; i <= n; i++)
    {
        in.a[i] = a[i];
        ax.a[i] = a[i];
    }
    in.build(1, 1, n);
    ax.build(1, 1, n);
    int r = -1;
    int j = n;
    int inn = 1e9, axx = 0, inn2 = 0;
    int pos1 = in.get(1, n);
    int pos2 = in.get(pos1 + 1, n);
    int pos3 = in.get(1, pos1 - 1);
    inn = min(min(a[pos1], a[pos2]), a[pos3]);
    if (inn == a[pos1])
    {
        inn2 = min(a[pos2], a[pos3]);
    }
    if (inn == a[pos2])
    {
        inn2 = min(a[pos1], a[pos3]);
    }
    if (inn == a[pos3])
    {
        inn2 = min(a[pos2], a[pos1]);
    }
    int pos4 = ax.get(1, n);
    axx = a[pos4];
    for (int i = 1; i < n; i++)
    {
        j = n;
        inn = 1e9, axx = 0;
        pos1 = in.get(i, j);
        pos2 = in.get(pos1 + 1, j);
        pos3 = in.get(i, pos1 - 1);
        inn = min(min(a[pos1], a[pos2]), a[pos3]);
        if (inn == a[pos1])
        {
            inn2 = min(a[pos2], a[pos3]);
        }
        if (inn == a[pos2])
        {
            inn2 = min(a[pos1], a[pos3]);
        }
        if (inn == a[pos3])
        {
            inn2 = min(a[pos2], a[pos1]);
        }
        axx = a[ax.get(i, j)];
        cout << i << " " << inn << " " << inn2 << " " << pos1 << " " << pos2 << " " << pos3 << " \n";
        while (inn + inn2 <= axx)
        {
            j--;
            if (i == j)
                break;
            inn = 1e9, axx = 0;
            pos1 = in.get(i, j);
            pos2 = in.get(pos1 + 1, j);
            pos3 = in.get(i, pos1 - 1);
            inn = min(min(a[pos1], a[pos2]), a[pos3]);
            if (inn == a[pos1])
            {
                inn2 = min(a[pos2], a[pos3]);
            }
            if (inn == a[pos2])
            {
                inn2 = min(a[pos1], a[pos3]);
            }
            if (inn == a[pos3])
            {
                inn2 = min(a[pos2], a[pos1]);
            }
            pos4 = ax.get(i, j);
            axx = a[pos4];
            // cout << i << j;
        }
        r = max(j - i + 1, r);
    }
    cout << r;
}
