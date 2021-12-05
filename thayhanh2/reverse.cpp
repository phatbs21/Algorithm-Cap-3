#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll int64_t
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;

ll f[1000005][2][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("reverse.inp", "r", stdin);
    freopen("reverse.out", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<string> s(n + 1);
    vector<string> flip(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        string s_temp = s[i];
        reverse(s_temp.begin(), s_temp.end());
        flip[i] = s_temp;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                if (f[i - 1][0][j] == -1 && f[i - 1][1][j] == -1)
                    f[i][j][k] = -1;
                else
                {
                    f[i][j][k] = 1e15;
                    string si1, si2;
                    if (k == 0)
                        si1 = s[i];
                    else
                        si1 = flip[i];
                    if (j == 0)
                        si2 = s[i - 1];
                    else
                        si2 = flip[i - 1];
                    if (si1 < si2)
                    {
                        f[i][j][k] = -1;
                        continue;
                    }
                    if (f[i - 1][0][j] != -1)
                    {
                        f[i][j][k] = min(f[i][j][k], f[i - 1][0][j] + k * a[i]);
                    }
                    if (f[i - 1][1][j] != -1)
                    {
                        f[i][j][k] = min(f[i][j][k], f[i - 1][1][j] + k * a[i]);
                    }
                }
            }
        }
    }
    long long ans = 1e15;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            if (f[n][i][j] != -1)
                ans = min(ans, f[n][i][j]);
    if (ans == 1e15)
        cout << "-1";
    else
        cout << ans;
}
