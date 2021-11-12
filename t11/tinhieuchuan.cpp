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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("tinhieu.inp", "r", stdin);
    freopen("tinhieu.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> f0(n + 2, 0), f1(n + 2, 0);
    int pre;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0)
        {
            if (pre == 1 || i == 1)
            {
                f0[i] = f0[i + 1] + 1;
                f1[i] = f1[i + 1];
                pre = 0;
            }
            else
            {
                f0[i] = f0[i + 1];
                f1[i] = f1[i + 1];
            }
        }
        else
        {
            if (pre == 0 || i == 1)
            {
                f0[i] = f0[i + 1];
                f1[i] = f1[i + 1] + 1;
                pre = 1;
            }
            else
            {
                f0[i] = f0[i + 1];
                f1[i] = f1[i + 1];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << f1[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << f0[i] << " ";
    cout << endl;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            f[i] = f[i - 1] + max(min(f0[i + 1], f1[i + 1]), 0);
        }
        else
        {
            f[i] = f[i - 1] + max(min(f0[i + 1], f1[i + 1]), 0);
        }
    }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << " ";
    // }
    // cout << endl;

    cout << f[n];
}
