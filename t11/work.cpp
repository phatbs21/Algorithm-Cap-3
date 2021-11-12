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
int t[1000006];
int p[1000006];
int f[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("WORK.INP", "r", stdin);
    freopen("WORK.OUT", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int j = 1; j < n; j++)
        cin >> p[j];
    f[0] = 0;
    f[1] = t[1];
    for (int i = 2; i <= n; i++)
    {
        f[i] = min(t[i] + f[i - 1], f[i - 2] + p[i - 1]);
    }
    cout << f[n];
}
