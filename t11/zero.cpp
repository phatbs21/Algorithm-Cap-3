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
#define MAX 1009
int a[MAX][MAX];
int f[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("zero.inp", "r", stdin);
    freopen("zero.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        f[i][0] = 1;
        f[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i][j] == 0)
            if (a[i - 1][j] == 0 && a[i][j - 1] == 0)
                f[i][j] == 0;
            else if (a[i - 1][j] == 0)
                f[i][j] = a[i - 1][j];
            else if (a[i][j - 1] == 0)
                f[i][j] = a[i][j];
            else
                f[i][j] = a[i][j];
        }
    }
}
