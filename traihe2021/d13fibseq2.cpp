#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
#ifndef ONLINE_JUDGE
    freopen("d13fibseq2.inp", "r", stdin);
#endif
    ll n;
    cin >> n;
    ll tong = 0;
    vector<ll> a(n + 1, 0);
    for (ll i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
        tong += a[i];
    }
    if (n <= 20)
    {
        ll best = LLONG_MAX - 100;
        ll mut = (1 << n) - 1;
        map<ll, ll> f;
        ll A, B, C;
        cout << mut << "\n";
        for (ll t = 1; t <= mut; t++)
        {
            ll s = 0;
            for (ll i = 0; i <= n - 1; i++)
            {
                if ((t & (1 << i)) > 0)
                {
                    s += a[i];
                }
            }
            if (s <= tong / 3)
                f[t] = s;
            else
            {
                for (ll i = 0; i <= n - 1; i++)
                {
                    if ((t & (1 << i)) > 0)
                    {
                        f[t] = max(f[t], f[t ^ (1 << i)]);
                    }
                }
                A = f[t];
                B = tong - s;
                C = s - A;
                if (A <= B && B <= C)
                    best = min(best, C - A);
            }
        }
        cout << best;
    }
    else
    {
        map<int, map<int, map<int, int>>> f;
        f[0][0][0] = 0;
        priority_queue<ll> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(f[0][0][0]);
        }
    }
}