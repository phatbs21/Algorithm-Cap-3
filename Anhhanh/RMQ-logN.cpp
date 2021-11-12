#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MASK(i) (1LL << (i))

int a[10001];
int f[10000][22];

long long getMax(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(f[l][k], f[r - MASK(k) + 1][k]);
}
int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    for (int j = 1; j <= 19; j++)
    {
        for (int i = 1; i <= n - MASK(j) + 1; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + MASK(j - 1)][j - 1]);
        }
    }
    for (int i = 0; i < t; i++)
    {
        
        int z, z1;
        cin >> z >> z1;
        cout << getMax(z, z1) << " ";
    }
}