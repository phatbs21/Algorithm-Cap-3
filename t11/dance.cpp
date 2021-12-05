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
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    // 1 1 2 5
    // 2 3 6
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    a.resize(n + 1);
    b.resize(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> b[j];
    }
    vector<int> kq;
    kq.resize(n * m + 1);
    int q;
    cin >> q;
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            kq[++dem] = a[i] * b[j];
        }
    }
    // cout << "\n";
    sort(kq.begin() + 1, kq.end());
    for (int i = 1; i <= n * m; i++)
        cout << kq[i] << " ";
    cout << endl;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        int vt_x = (lower_bound(kq.begin() + 1, kq.end(), x) - (kq.begin()));
        int vt_y = (upper_bound(kq.begin() + 1, kq.end(), y) - (kq.begin()));
        cout << vt_x << " " << vt_y << "\n";
        if (vt_y - vt_x >= 0)
        {
            cout << vt_y - vt_x;
        }
        else
            cout << 0;
        cout << "\n";
    }
}
