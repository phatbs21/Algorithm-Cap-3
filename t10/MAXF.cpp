#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
bool fc(pair<int, int> i, pair<int, int> j)
{
    return (i.fi == j.fi);
}
bool fv(pair<int, int> i, pair<int, int> j)
{
    if (i.fi < j.fi)
        return true;
    else
        return false;
}
int main()
{
    freopen("MAXF.INP", "r", stdin);
    freopen("MAXF.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(), a.end(), fv);

    auto ip = unique(a.begin(), a.end(), fc);
    a.resize(distance(a.begin(), ip));
    if (a.size() < 2)
    {
        cout << -1;
        return 0;
    }
    n = a.size();

    double mx = INT_MIN;
    int v1, v2;
    for (int i = 0; i < n - 1; i++)
    {
        if ((double)a[i].fi / (double)a[i + 1].fi > mx)
        {
            mx = (double)a[i].fi / (double)a[i + 1].fi;
            v1 = a[i].fi;
            v2 = a[i + 1].fi;
        }
    }
    cout << v1 << " " << v2;
}