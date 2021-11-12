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

#define MAX 3030
int numRow, numCol, areaRow, areaCol;
int value[MAX][MAX], sum[MAX][MAX];

void init(void)
{
#ifndef ONLINE_JUDGE
    freopen("chatluong2.inp", "r", stdin);
    freopen("chatluong2.out", "w", stdout);
#endif
    scanf("%d%d%d%d", &numRow, &numCol, &areaRow, &areaCol);
    FOR(i, 1, numRow)
    FOR(j, 1, numCol)
    scanf("%d", &value[i][j]);
}

int getSum(int top, int bot, int left, int right)
{
    return sum[bot][right] - sum[top - 1][right] - sum[bot][left - 1] + sum[top - 1][left - 1];
}
bool ok(int level)
{
    FOR(i, 1, numRow)
    FOR(j, 1, numCol)
    sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (value[i][j] >= level ? 1 : -1);
    
    for (int i = 1; i <= numCol; i++)
    {
        for (int j = 1; j <= numRow; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    FOR(i, 1, numRow - areaRow + 1)
    FOR(j, 1, numCol - areaCol + 1)
    if (getSum(i, i + areaRow - 1, j, j + areaCol - 1) > 0)
        return true;
    return false;
}

int process(void)
{
    int L = 1, R = numRow * numCol;
    while (true)
    {
        if (L == R)
            return R;
        if (R - L == 1)
            return ok(R) ? R : L;
        int M = (L + R) >> 1;
        if (ok(M))
            L = M;
        else
            R = M - 1;
    }
}

int main(void)
{
    init();
    cout << process() << endl;
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/