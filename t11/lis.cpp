#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.fi == y.fi)
        return x.se < y.se;
    else
        return x.fi < y.fi;
}
int main()
{
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<int> b;
    vector<int> f(100000, 0);
    int x, y;
    while (cin >> x >> y)
    {
        a.push_back(mp(x, y));
    }

    sort(a.begin(), a.end(), cmp);

    int kq = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (a[i].se > a[j].se && a[i].fi > a[j].fi)
            {
                f[i] = max(f[i], f[j]);
            }
        }
        f[i]++;
        kq = max(kq, f[i]);
    }
    cout << kq << "\n";
    int fi = INT_MAX, se = INT_MAX;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (f[i] == kq && a[i].fi < fi && a[i].se < se)
        {
            b.push_back(i);
            fi = a[i].fi;
            se = a[i].se;
            kq--;
        }
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        cout << a[b[i]].fi << " " << a[b[i]].se << "\n";
    }
}
