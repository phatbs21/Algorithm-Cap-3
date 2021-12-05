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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("letters.inp", "r", stdin);
    freopen("letters.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int n, m, kk;
    cin >> n >> m >> kk;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    char f[405][405];
    int tong[405][405];
    memset(tong, 0, sizeof(tong));
    for (int i = 1; i <= n; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++)
        f[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = s[i][j - 1];
            if (f[i][j] == 'a')
                tong[i][j] = tong[i - 1][j] + tong[i][j - 1] + 1 - tong[i - 1][j - 1];
            else
                tong[i][j] = tong[i - 1][j] + tong[i][j - 1] - tong[i - 1][j - 1];
        }
    }

    int dem = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            for (int k = i + 1; k <= m; k++)
            {
                for (int l = j + 1; l <= m; l++)
                {
                    cout << i << " " << j << " " << k << " " << l << " " << tong[k][l] - tong[i - 1][j] - tong[i][j - 1] + tong[i - 1][j - 1] << endl;
                    if (tong[k][l] - tong[i - 1][j] - tong[i][j - 1] + tong[i - 1][j - 1] <= kk && f[i][j] == f[i][l] && f[i][j] == f[k][l] && f[i][j] == f[k][j])
                    {
                        // cout << i << " " << j << " " << l << " " << k << " " << tong[k][l] - tong[i - 1][j] - tong[i][j - 1] + tong[i - 1][j - 1] << endl;
                        dem++;
                    }
                }
            }
        }
    }
    cout << dem;
}
