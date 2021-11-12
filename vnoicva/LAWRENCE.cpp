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
int f[502][502], prefix[502] = {0}, a[502];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[n] - prefix[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            f[i][j] = prefix[j];
            //cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    for (int i = 1; i <= m; i++)
    {
        int minn = INT_MAX;
        int vt = 0;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
        }
        for (int j = 1; j <= n; j++)
        {
            int temp = f[i][j];
            f[i][j] = 0;
            int tong = 0;
            int f2[502];
            memset(f2, 0, sizeof(f2));
            for (int k = 1; k <= n; i++)
            {
                if (k <= j)
                    f2[k] = f2[k] - temp;
                else
                    f2[k] = f[i][k];
            }
            for (int k = 1; k <= n; i++)
            {
                tong += f2[k] * a[k];
            }
            if (tong < minn)
            {
                minn = tong;
                vt = j;
            }
            else
                f[i][j] = temp;
        }
        for (int k = 0; k <= n; k++)
        {
            cout << f[i][k] << " ";
        }
        cout << endl;
        f[i][vt] = 0;
    }
    int tong = 0;
    for (int i = 1; i <= n; i++)
        tong += f[m][i];
    cout << tong;
}
