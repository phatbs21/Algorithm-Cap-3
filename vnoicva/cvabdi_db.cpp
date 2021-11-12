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
#define mp make_pair
#define pi 3.14159
typedef pair<ll, ll> pii;
ll point[4002][4002]; // x,y
vector<pair<ll, ll>> toaDo;
// chuyen hinh tron ve (0,0)
void prepareTrucTung(ll &x, ll u)
{
    x -= u;
    return;
}
void prepareTrucHoanh(ll &y, ll v)
{
    y -= v;
    return;
}
//ghi toa do
void trucTung(ll x)
{
    for (ll i = 0; i <= 4000; i++)
    {
        point[i][0] = 1;
    }
}
void trucHoanh(ll y)
{
    for (ll i = 0; i <= 4000; i++)
    {
        point[0][i] = 1;
    }
}
void printBang()
{
    for (ll i = 0; i <= 4000; i++)
    {
        for (ll j = 0; j <= 4000; j++)
            cout << point[i][j] << " ";
        cout << endl;
    }
}
void taoDanhSachToaDo()
{
    for (ll i = 0; i <= 4000; i++)
    {
        for (ll j = 0; j <= 4000; j++)
        {
            if (point[i][j] > 0)
            {
                toaDo.pb(mp(i - 2000, j - 2000));
            }
        }
    }
}
void printToaDo()
{
    for (ll i = 0; i < toaDo.size(); i++)
    {
        cout << toaDo[i].fi << " " << toaDo[i].se << "\n";
    }
}
vector<ll> p;
void prepareProcess(ll n)
{
    for (ll i = 0; i < n; i++)
    {
        p[i] = toaDo[i].fi * toaDo[i].fi + toaDo[i].se * toaDo[i].se;
    }
    sort(p.begin(), p.end());
}
ll query(ll n, ll rad)
{
    ll start = 0, end = n - 1;
    while ((end - start) > 1)
    {
        ll mid = (start + end) / 2;
        double tp = sqrt(p[mid]);

        if (tp > (rad * 1.0))
            end = mid - 1;
        else
            start = mid;
    }
    double tp1 = sqrt(p[start]), tp2 = sqrt(p[end]);
    if (tp1 > (rad * 1.0))
        return 0;
    else if (tp2 <= (rad * 1.0))
        return end + 1;
    else
        return start + 1;
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
    ll n, m, u, v, r;
    cin >> n >> m >> u >> v >> r;
    vector<ll> a(1, 0), b(1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ll x_temp;
        cin >> x_temp;
        a.pb(x_temp);
    }
    for (ll i = 1; i <= m; i++)
    {
        ll y_temp;
        cin >> y_temp;
        b.pb(y_temp);
    }
    sort(b.begin() + 1, b.end());
    for (ll i = 1; i <= n; i++)
    {
        ll temp = sqrt(r * r * 1LL - (a[i] - u) * (a[i] - u) * 1LL);
        if (temp >= 0)
        {
            a[0] += max((ll)0, (ll)((upper_bound(b.begin() + 1, b.end(), v + temp) - 1) - (lower_bound(b.begin() + 1, b.end(), v - temp)) + 1));
        }
    }
    b[0] = n * m - a[0];
    cout << abs(a[0] - b[0]);
    // map<ll, bool> check_x, check_y;
    // for (ll i = 1; i <= n; i++)
    // {
    //     ll x_temp;
    //     cin >> x_temp;
    //     if (check_x[x_temp] == false)
    //     {
    //         prepareTrucHoanh(x_temp, u);
    //         trucHoanh(x_temp);
    //         check_x[x_temp] = true;
    //     }
    // }
    // for (ll j = 1; j <= m; j++)
    // {
    //     ll y_temp;
    //     cin >> y_temp;
    //     if (check_y[y_temp] == false)
    //     {
    //         prepareTrucTung(y_temp, v);
    //         trucTung(y_temp);
    //         check_y[y_temp] = 1;
    //     }
    // }
    // printBang();
    // taoDanhSachToaDo();
    // p.assign(toaDo.size(), 0);
    // cout << query(toaDo.size(), pi * (r * r));
}
