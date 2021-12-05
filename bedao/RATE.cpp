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
typedef pair<ll, ll> pii;
string toBinary(ll n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}
string f[1000000];
int main()
{
    // #if ONLINE_JUDGE
    // #else
    //     freopen("input.inp", "r", stdin);
    //     //freopen("output.out", "w", stdout);
    // #endif
    ll n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    n = s.size();
    ll dem = 1;
    ll maxx = INT_MAX;
    ll maxa = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            dem++;
            if (maxa < maxx)
                maxx = maxa;
            maxa = 0;
        }
        else
            maxa += 7;
    }
    if (maxa < maxx)
        maxx = maxa;
    cout << dem << " " << maxx << "\n";

    dem = 1;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] != '#')
        {
            //cout << toBinary(s[i]) << "\n";
            // cout << f[dem].size() << "*";
            if (f[dem].size() >= maxx)
            {
                //cout << 1;
                continue;
            }
            f[dem] = toBinary(s[i]) + f[dem];
        }
        else
        {
            dem++;
        }
    }
    if (f[dem].size() < maxx)
    {
        maxx = f[dem].size();
    }
    ll so0 = 0, so1 = 0;
    // for(int i=dem;i>=0;i++)
    // {
    //     if(dem)
    // }
    for (ll i = 1; i <= dem; i++)
    {
        //cout << f[i] << "\n";
        for (ll j = 0; j < maxx; j++)
        {
            if (f[i][j] == '1')
                so1++;
            else
                so0++;
        }
    }
    //cout << so1 << " " << so0 << "\n";
    cout << setprecision(9) << fixed << (double)so1 / (double)so0;
}
