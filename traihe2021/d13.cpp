#include <bits/stdc++.h>
using namespace std;
long long  int a[100000], f[6005][6001], n, d;
 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    n = n * 2;
    for (long long int i = 1; i <= n; i++)
        cin >> a[i];
    for (long long int i = n; i >= 1; i--)
        for (long long int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            if (abs(a[i] - a[j]) <= d)
                f[i][j] = f[i + 1][j - 1] + 1;
        }
    cout << f[1][n] / 2;
}