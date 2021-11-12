#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll long long int
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
vector<int> a;
int f[3][1000 + 2][1000 + 2];

void solve()
{
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    memset(f, 0, sizeof(f));
    int so[] = {0, 3, 1, -4};
    f[1][1][1] = f[2][1][1] = f[3][1][1] = a[1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int i_tmp = 1, j_tmp = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; i++)
        {
            for (int k = 1; k <= 3 && i >= 3 && j >= 3; k++)
                f[i][j] = max(max(max(f[i][j], f[i - 1][j - 1] * so[k]), f[i - 1][j] * so[k]), f[i][j - 1] * so[k]);
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
#ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }
    }
