#include <bits/stdc++.h>
using namespace std;
int64_t n, r, t, k;
vector<int64_t> p;
const int64_t mod = 998244353;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

int64_t fastPow(int64_t so, int64_t mu)
{
    if (mu == 0)
        return 1;
    if (mu & 1)
        return fastPow(so, mu - 1) * so % mod;
    else
    {
        int64_t b = fastPow(so, mu / 2) % mod;
        return b * b % mod;
    }
}
void subTask1()
{
    cout << fastPow(r + 1, t) % mod;
}
vector<int64_t> tong;
int64_t dem = 0;
bool kiemTra()
{
    for (int64_t i = 1; i <= n - 1; i++)
        for (int64_t j = 2; j <= n; j++)
        {
            if (abs((tong[j] + p[j]) - (tong[i] + p[i])) > k)
            {
                return false;
            }
        }
    return true;
}
void inra(int u)
{
    cout << u << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << tong[i] << " ";
    }
    cout << endl;
}
void backTrack(int64_t u)
{

    if (u > n)
    {
        inra(u);
        if (kiemTra() == true)
            dem++;
        return;
    }
    for (int64_t i = 0; i <= r; i++)
    {
        tong[u] = i;
        backTrack(u + 1);
    }
}
void subTask2()
{
    tong.assign(n + 1, 0);
    backTrack(1);
    cout << dem % mod;
}
/*
Gọi F(i, j) là số cách để sau i lượt ăn được chính xác j con mực (số dãy độ dài i có tổng bằng j). Công thức QHĐ:
+ Với i = 0, ta có F(i, 0) = 1 và F(i, j) = 0 với mọi j > 0.
+ Với i > 0, ta có F(i, j) = tổng F(i-1, j-k) -> F(i-1, j).
*/
void add(int64_t &x, int64_t y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}
void sub(int64_t &x, int64_t y)
{
    x -= y;
    if (x < 0)
        x += mod;
}
// hai hàm thay cho phép % mod
int64_t f[111][1111 * 111];
#define MAX_EAT 1010
#define MAX_TURN 111
#define MAX_PERSON 11
void subTaskFull1()
{
    f[0][0] = 1;
    for (int64_t i = 1; i < t; i++)
    {
        for (int64_t j = 0; j <= i * 1111; i++)
        {
            for (int64_t k = 0; k <= 1111; k++)
            {
                if (j >= k)
                    add(f[i][j], f[i - 1][j - 1]);
            }
        }
    }
}
int64_t sum[111][111 * 1111]; // mảng tổng dồn
int64_t cntWay(int64_t minAll, int64_t maxAll)
{
    int64_t res = 1;
    for (int64_t i = 1; i <= n; i++)
    {
        int64_t low = minAll - p[i];
        int64_t high = maxAll - p[i];
        maximize(low, 0);
        minimize(high, r * t);
        if (low > high)
            return 0;
        int64_t mul = sum[t][high];
        if (low > 0)
            sub(mul, sum[t][low - 1]);
        res = 1LL * res * mul % mod;
    }
    return res;
}
void subTaskFull2()
{ //QHD xu li cho tung nguoi
    f[0][0] = 1;
    for (int64_t i = 0; i <= t * r; i++)
        sum[0][i] = 1;
    for (int64_t i = 1; i <= t; i++)
    {
        for (int64_t j = 0; j <= i * r; j++)
        {
            f[i][j] = sum[i - 1][j];
            if (j > r)
                sub(f[i][j], sum[i - 1][j - r - 1]);
            sum[i][j] = f[i][j];
            if (j > 0)
                add(sum[i][j], sum[i][j - 1]);
            // cout<<sum[i][j];
        }
        for (int64_t j = i * r + 1; j <= t * r; j++)
        {
            f[i][j] = 0;
            sum[i][j] = sum[i][j - 1];
        }
    }
    // Xu li tap the
    int64_t minStart = p[1];
    for (int64_t i = 1; i <= n; i++)
    {
        minimize(minStart, p[i]);
    }
    int64_t res = 0;
    for (int64_t i = minStart; i <= minStart + r * t; i++)
    {
        int64_t j = i + k;
        add(res, cntWay(i, j));
        sub(res, cntWay(i + 1, j));
    }
    cout << res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("squidsgame.inp", "r", stdin);
    freopen("squidsgame.out", "w", stdout);
#endif
    cin >> n >> r >> t >> k; //η , λ, τ và δ (1 ≤ η≤ 101, 1 ≤ λ ≤ 103, 1 ≤ τ ≤ 102, 0 ≤ δ ≤ 106)
                             //n , r, t,   k
    p.resize(n + 2);
    for (int64_t i = 1; i <= n; i++)
        cin >> p[i];
    if (n == 1)
        subTask1();
    // else if (n <= 3 && r <= 6 && t <= 3)
    //     subTask2();
    else
        //    subTaskFull1();// do phuc tap cao
        subTaskFull2();
}
