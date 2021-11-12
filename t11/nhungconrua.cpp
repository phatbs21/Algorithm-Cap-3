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
typedef pair<ll, ll> pii;

void xuli()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll kc_a = min(a, min(b, c));
    ll kc_b = max(a, max(b, c));
    ll y_giua = a + b + c - kc_a - kc_b;
    if (kc_a == y_giua && y_giua == kc_b)
        cout << "0";
    else
    {
        if (kc_a == y_giua && y_giua < kc_b)
        {
            kc_a++;
            y_giua++;
            kc_b = max(y_giua, kc_b - 1);
        }
        else if (kc_a < y_giua && y_giua == kc_b)
        {
            y_giua--;
            kc_b--;
            kc_a = min(kc_a + 1, y_giua);
        }
        else
        {
            kc_a++;
            kc_b--;
        }
        cout << 2 * (kc_b - kc_a);
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll q;
    cin >> q;
    while (q--)
    {
        xuli();
    }
}
