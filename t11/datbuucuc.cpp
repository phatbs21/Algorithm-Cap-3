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
const ll oo = 100000000;
typedef pair<ll, ll> pii;
ll a[205][205];
ll t[205][205];
vector<ll> trace(ll u, ll v)
{
    vector<ll> path;
    do
    {
        path.pb(u);
        u = t[u][v];
    } while (path.back() != v);
    return path;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    for (ll i = 0; i <= 201; i++)
    {
        for (ll j = 0; j <= 201; j++)
        {
            a[i][j] = oo;
            t[i][j] = oo;
        }
    }
    for (ll i = 1; i <= 201; i++)
    {
        t[i][i] = 0;
    }
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        a[temp1][temp2] = temp3;
        a[temp2][temp1] = temp3;
        t[temp1][temp2] = temp2;
        t[temp2][temp1] = temp1;
    }
    for (int i = 1; i <= n; i++)
    {
        ll flag = true;
        for (ll j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if (a[i][j] < oo - 1)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true)
        {
            cout << "NOT FOUND";
            return 0;
        }
    }
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    t[i][j] = t[i][k];
                }
            }
    // for (int i = 0; i <= 201; i++)
    //     a[i][i] = 0;
    ll maxx = oo;
    ll vt1 = -1, vt2 = -1;
    ll dinh_min = -oo;
    for (ll i = 1; i <= n; i++)
    {
        dinh_min = -oo;
        ll vt1_temp = i, vt2_temp = -1;
        for (ll j = 1; j <= n; j++)
        {
            if (a[i][j] < oo && i != j)
                if (dinh_min < a[i][j])
                {
                    dinh_min = a[i][j];
                    vt1_temp = i;
                    vt2_temp = j;
                }
        }
        //cout << vt1_temp << " " << vt2_temp << " " << dinh_min << "\n";
        if (maxx > dinh_min)
        {
            maxx = dinh_min;
            vt1 = vt1_temp;
            vt2 = vt2_temp;
        }
    }
    cout << vt1 << "\n"
         << vt2 << " " << a[vt1][vt2] << "\n";
    vector<ll> path = trace(vt1, vt2);
    for (ll i = 0; i < (ll)path.size() - 1; i++)
    {
        cout << path[i] << "->";
    }
    cout << path[path.size() - 1];
}
