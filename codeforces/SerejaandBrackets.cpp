#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int optimal;
    int open;
    int close;
    Node(int op, int p, int c)
    {
        optimal = op;
        open = p;
        close = c;
    }
};
vector<Node> tree;
vector<char> a;
Node operator+(const Node &left, const Node &right)
{
    Node tong(0, 0, 0);
    int tmp = min(left.open, right.close);
    tong.optimal = left.optimal + right.optimal + tmp;
    tong.open = left.open + right.open - tmp;
    tong.close = left.close + right.close - tmp;
    return tong;
}
void inkq(Node temp)
{
    cout << "debug:" << temp.close << " " << temp.open << " " << temp.optimal << "\n";
    return;
}
void build(int i, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        if (a[l] == '(')
        {
            tree[i] = Node(0, 1, 0);
        }
        else
        {
            tree[i] = Node(0, 0, 1);
            //inkq(tree[i]);
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int n;
Node get_kq(int i, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return Node(0, 0, 0);
    }
    if (l >= u && v >= r)
    {
        return tree[i];
    }
    int mid = (l + r) / 2;
    return get_kq(i * 2, l, mid, u, v) + get_kq(i * 2 + 1, mid + 1, r, u, v);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("SerejaandBrackets.inp", "r", stdin);
#endif
    string s;
    cin >> s;
    n = (int)s.length();
    a.resize(n + 1);
    tree.assign(4 * n + 10, {0, 0, 0});

    for (int i = 0; i < (int)s.length(); i++)
        a[i + 1] = s[i];
    build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        Node kq = get_kq(1, 1, n, temp1, temp2);
        cout << kq.optimal * 2 << endl;
    }
}