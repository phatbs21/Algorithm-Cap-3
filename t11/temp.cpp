#include <bits/stdc++.h>
#define N 10001
using namespace std;
struct psi
{
    string fi;
    int sc, id;
};
psi a[N];
int n;
int CountNumber(string s)
{
    int CountNum = 0;
    for (auto x : s)
        if ('0' <= x && x <= '9')
            CountNum++;
    return CountNum;
}

bool cmp(psi X, psi Y)
{
    return (X.sc < Y.sc) || (X.sc == Y.sc && X.id < Y.id);
}
int main()
{
    freopen("input.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].sc = CountNumber(a[i].fi);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout << a[i].fi << '\n';
    return 0;
}
