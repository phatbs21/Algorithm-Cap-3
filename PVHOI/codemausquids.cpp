#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x) (std::isinf(x))
#define IS_NAN(x) (std::isnan(x))
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div ___div
#define next ___next
#define prev ___prev
#define left ___left
#define right ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
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
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const int MOD = 998244353;
void add(int &x, const int &y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}
void sub(int &x, const int &y)
{
    x -= y;
    if (x < 0)
        x += MOD;
}

#define MAX_EAT 1010
#define MAX_TURN 111
#define MAX_PERSON 11

int n, r, t, delta;
int f[MAX_TURN][MAX_EAT * MAX_TURN];
int sum[MAX_TURN][MAX_EAT * MAX_TURN];
int start[MAX_PERSON];

void init(void)
{
#ifndef ONLINE_JUDGE
    freopen("squidsgame.inp", "r", stdin);
    //freopen("squidsgame.out", "w", stdout);
#endif
    cin >> n >> r >> t >> delta;
    FOR(i, 1, n)
    cin >> start[i];
}

int cntWay(int minAll, int maxAll)
{
    int res = 1;
    FOR(i, 1, n)
    {
        int low = minAll - start[i];
        int high = maxAll - start[i];
        maximize(low, 0);
        minimize(high, r * t);
        if (low > high)
            return 0;

        int mul = sum[t][high];
        if (low > 0)
            sub(mul, sum[t][low - 1]);
        res = 1LL * res * mul % MOD;
    }
    return res;
}

void process(void)
{
    f[0][0] = 1;
    FOR(i, 0, t * r)
    sum[0][i] = 1;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= i * r; j++)
        {
            f[i][j] = sum[i - 1][j];
            if (j > r)
                sub(f[i][j], sum[i - 1][j - r - 1]);
            sum[i][j] = f[i][j];
            if (j > 0)
                add(sum[i][j], sum[i][j - 1]);
            cout<<sum[i][j];
        }
        for (int j = i * r + 1; j <= t * r; j++)
        {
            f[i][j] = 0;
            sum[i][j] = sum[i][j - 1];
        }
    }

    int minStart = start[1];
    FOR(i, 1, n)
    minimize(minStart, start[i]);
    int res = 0;
    FOR(i, minStart, minStart + r * t)
    {
        int j = i + delta;
        add(res, cntWay(i, j));
        sub(res, cntWay(i + 1, j));
    }
    cout << res << endl;
}

int main(void)
{
    REP(gspvhcute, 227)
    ios::sync_with_stdio(true);
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/