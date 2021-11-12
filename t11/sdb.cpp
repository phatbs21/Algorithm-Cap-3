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

    freopen("SDB.inp", "r", stdin);
    freopen("SDB.out", "w", stdout);
    int n;
    cin >> n;
    map<int, int> q;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.pb(x);
        q[x]++;
    }
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        if (q[a[i]] == 1)
            b.push_back(a[i]);
    }
    cout << b.size() << "\n";
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << "\n";
    }
}
