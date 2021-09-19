#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define cin f1
#define cout f2
#define FOR(i, n, m) for (ll i = n; i <= m; ++i)
using namespace std;
ifstream f1("nazi.inp");
ofstream f2("nazi.out");
char r, c, n, a[101][101], kq = 1;
long cnt = 0;
void inp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(a, 0, sizeof(a));
    cin >> r >> c >> n;
    FOR(i, 1, n)
    {
        ll u, v;
        cin >> u >> v;
        a[u][v] = 1;
        ++cnt;
    }
}
void out()
{
    FOR(i, 1, r)
    a[i][0] = a[i][c + 1] = 2;
    FOR(i, 1, c)
    a[0][i] = a[r + 1][i] = 2;
    while (0 == 0)
    {
        FOR(i, 1, r)
        {
            FOR(j, 1, c)
            {
                if (a[i][j] == 1)
                {
                    if (a[i][j + 1] == 0)
                    {
                        a[i][j + 1] = 1;
                        ++cnt;
                    }
                    if (a[i][j - 1] == 0)
                    {
                        a[i][j - 1] = 1;
                        ++cnt;
                    }
                    if (a[i - 1][j] == 0)
                    {
                        a[i - 1][j] = 1;
                        ++cnt;
                    }
                    if (a[i + 1][j] == 0)
                    {
                        a[i + 1][j] = 1;
                        ++cnt;
                    }
                }
            }
        }
        ++kq;
        if (cnt == r * c)
        {
            cout << kq;
            return;
        }
    }
}
int main()
{
    inp();
    out();
}