#include <bits/stdc++.h>
using namespace std;
int dem(string a, string b)
{
    int n = a.length(), m = b.length();
    int f[n + 1][m + 1] = {{0}};
    for (int i = 0; i <= m; ++i)
        f[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        f[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            else
                f[i][j] = f[i - 1][j];
        }
    }
    return f[n][m];
}
int main()
{
    int m, n;
    cin >> n >> m;
    string a;
    cin >> a;
    int tong = 0;
    for (int i = 0; i < m; i++)
    {
        string b;
        cin >> b;
        tong += dem(a, b);
    }
    cout << tong;
}
