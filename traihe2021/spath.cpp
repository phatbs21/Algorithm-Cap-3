#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> a(n + 1), b(n + 1);
int xoa(int i)
{
    return a[i].size();
}
int bac(int i)
{
    return n - a[i].size() - 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1].push_back(t2);
        a[t2].push_back(t1);
    }
    int q;
    cin >> q;
    vector<int> x(q + 1), y(q + 1);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (xoa(x) < xoa(y))
        {
            swap(x, y);
        }
    }
}