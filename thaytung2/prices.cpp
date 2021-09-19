#include <bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 100009
#define fi first
#define se second
#define pb push_back


int n, a[maxn], mark[maxn];

void init()
{
    cin >> n;
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void solve()
{
    int l = 1, r = 2;
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= n;)
    {
        while (mark[i] == 1)
            i++;
        while (a[r] != a[i] * 4 / 3)
            r++;
        if (r <= n)
            cout << a[i] << endl;
        mark[r] = 1;
        i++;
    }
}

int main()
{
    init();
    solve();
}
