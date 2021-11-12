#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
#define ll long long int
ll r, c, h, w;
ll a[3030][3030];
vector<ll> visit;
bool minimize(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
ll sub3Xuli(ll x, ll y, ll xx, ll yy) // xu li thuoc sub3
{
    vector<ll> q;
    for (ll i = x; i < xx; i++)
    {
        for (ll j = y; j < yy; j++)
        {
            q.push_back(a[i][j]);
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    sort(q.begin(), q.end());
    ll n = q.size();

    if (r * c % 2 == 0)
    {
        //cout << q[n/2] << endl;
        return q[n / 2];
    }
    else
    {
        //cout << q[n / 2] << endl;
        return q[n / 2];
    }
}

void subtask3() // sub 3
{
    ll mx = INT_MIN;
    for (ll i = 0; i <= r - h; i++)
        for (ll j = 0; j <= c - w; j++)
        {
            ll temp = sub3Xuli(i, j, i + h, j + w);
            if (mx < temp)
                mx = temp;
            //cout << i << " " << j << " " << temp << "\n";
        }
    cout << mx;
}
ll getMedien()
{
    ll dem = 0;
    for (ll i = 1; i <= r * c; i++)
    {
        if (visit[i] == true)
        {
            if (++dem == (h * w / 2 + 1))
                return i;
        }
    }
}
void subtask4()
{
    ll mx = INT_MIN;
    visit.assign(r * c + 10, false);
    for (ll i = 0; i <= r - h; i++)
        for (ll j = 0; j <= c - w; j++)
        {
            for (ll x = 0; x < h; x++)
                for (ll y = 0; y < w; y++)
                {
                    visit[a[i + x][j + y]] = true;
                }
            ll temp = getMedien();
            if (mx < temp)
                mx = temp;
            for (ll x = 0; x < h; x++)
                for (ll y = 0; y < w; y++)
                {
                    visit[a[i + x][j + y]] = false;
                }
        }
    cout << mx;
}
ll sum[3030][3030];
ll getSum(ll x, ll xx, ll y, ll yy) // mảng cộng dồn 2 chiềU
{
    if (x > 0 && y > 0)
        return (sum[xx][yy] - sum[x - 1][yy] - sum[xx][y - 1] + sum[x - 1][y - 1]);
    else if (x <= 0 && y <= 0)
        return sum[xx][yy];
    else if (x <= 0)
        return (sum[xx][yy] - 0 - sum[xx][y - 1] + 0);
    else if (y <= 0)
        return (sum[xx][yy] - sum[x - 1][yy] - 0);
}
ll kiemtraSub7(ll level)
{
    for (ll i = 0; i < r; i++)
        for (ll j = 0; j < c; j++)
        {
            if (j - 1 >= 0 && i - 1 >= 0)
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (a[i][j] >= level ? 1 : -1); // mẹo trung vị
            else if (j - 1 < 0 && i - 1 < 0)
                sum[i][j] = (a[i][j] >= level ? 1 : -1);
            else if (j - 1 < 0)
                sum[i][j] = sum[i - 1][j] + (a[i][j] >= level ? 1 : -1);
            else if (i - 1 < 0)
                sum[i][j] = sum[i][j - 1] + (a[i][j] >= level ? 1 : -1);
        }
    // cout << level << "\n";
    // for (ll i = 0; i < r; i++)
    // {
    //     for (ll j = 0; j < c; j++)
    //     {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (ll i = 0; i <= r - h; i++)
        for (ll j = 0; j <= c - w; j++)
        {
            if (getSum(i, i + h - 1, j, j + w - 1) > 0)
            {
                return true;
            }
        }
    return false;
}
ll xuliSub7()
{
    ll l = 1, ri = r * c;
    while (true)
    {

        if (l == ri)
            return ri;
        if (ri - l == 1)
            return kiemtraSub7(ri) ? ri : l;
        ll mid = (l + ri) >> 1;
        if (kiemtraSub7(mid))
            l = mid;
        else
            ri = mid - 1;
        //cout << l << " " << ri << " " << mid << "\n";
    }
}
ll subTask7()
{
    cout << xuliSub7() << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("chatluong2.inp", "r", stdin);
    freopen("chatluong.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> h >> w;
    // a.resize(r);
    // for (ll i = 0; i < r; i++)
    //     a[i].resize(c);
    for (ll i = 0; i < r; i++)
        for (ll j = 0; j < c; j++)
            cin >> a[i][j];
    if (h == 1 && w == 1)
        cout << r * c;
    else if (h == r && w == c)
        cout << (r * c + 1) / 2;
    else if (r <= 100 && c <= 100)
    {
        subtask3(); // kĩ thuật sort
        //subtask4(); // sử dụng mảng đếm phân phối
        //sử dụng 1 trong 2 cái tùy thích
    }
    else
        subTask7();
    // cout << "\n"
    //    << clock() / (double)1000;
}