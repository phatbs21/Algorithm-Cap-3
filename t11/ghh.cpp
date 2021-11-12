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
vector<int> d;

void check(int u)
{
    // cout << endl;
    //  cout << u << " ";
    ll sum = 0;
    for (int i = 1; i <= u / 2; i++)
    {
        if (u % i == 0)
        {
            sum += (ll)i;
            //   cout << i << " ";
        }
    }
    //  cout << endl;
    if (sum >= (ll)u)
        d.push_back(u);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("ghh.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        check(x);
    }
    cout << d.size() << "\n";
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << "\n";
    }
}
