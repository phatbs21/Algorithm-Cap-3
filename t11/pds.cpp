#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
//█▀▀ ▄▀█ █▀▄▀█ █▀▀   █▀█ ▄▀█ █▀▀ ░   █▀█ ▄▀█ █▀▀   █░█ ▄▀█ █   █░░
//█▄█ █▀█ █░▀░█ ██▄   █▀▄ █▀█ █▄▄ █   █▀▄ █▀█ █▄▄   ▀▄▀ █▀█ █   █▄▄
// tran hoang vu with love =))))))))) 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define max_so 10
using namespace std;
ll dp[max_so + 1][max_so * 9 + 1][max_so * 9 + 1][max_so * 9 + 1][2];
//vector<vector<vector<vector<vector<ll>>>>> test(max_so + 1, vector<vector<ll> >(max_so * 9 + 1, vector<ll>(max_so * 9 + 1, vector<ll>(vector<ll>(max_so * 9 + 1, vector<ll>(2, 0))))));
void check(ll n, ll l, ll current_s, ll r, ll po)
{
    if (n <= 0 || l == 0)
        return;
    ll dem = 0, last_dem = 0;
    for (ll i = po; i <= 9; i++)
    {
        for (ll s = max((ll)1, current_s + i); s <= 9 * max_so; s++)
            dem += dp[l - 1][s - current_s - i][s][(r * i) % s][0];
        if (n <= dem)
        {
            cout << i;
            check(n - last_dem, l - 1, current_s + i, r * i, 0); // tim doan
            break;
        }
        last_dem = dem;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
#endif
    for (ll i = 1; i <= 9 * max_so; i++)
        dp[0][0][i][0][0] = 1;
    for (ll l = 1; l <= max_so; l++)
    {
        for (ll s = 0; s <= 9 * l; s++)
        {
            ll maxD = min((ll)9, s);
            for (ll MOD = 1; MOD <= 9 * max_so; MOD++)
            {
                for (ll r = 0; r < MOD; r++)
                {
                    dp[l][s][MOD][r][0] = dp[l - 1][s][MOD][0][0];
                    dp[l][s][MOD][r][1] = 0;
                    for (ll d = 1; d <= maxD; d++)
                        dp[l][s][MOD][r][1] += dp[l - 1][s - d][MOD][(r * d) % MOD][0];
                    dp[l][s][MOD][r][0] += dp[l][s][MOD][r][1];
                }
            }
        }
    }
    ll n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (ll l = 1; l <= max_so; l++)
        {
            ll dem = 0;
            for (ll s = 1; s <= 9 * l; s++)
                dem += dp[l][s][s][1 % s][1];
            if (dem < n)
                n -= dem;
            else
            {
                check(n, l, 0, 1, 1);
                cout << "\n";
                break;
            }
        }
    }
}