#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
struct Query
{
    int L, R;
};

int main()
{
    freopen("test.out", "w", stdout);
    int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    Query query[] = {{0, 4},
                     {4, 7},
                     {7, 8}};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(query) / sizeof(query[0]);
    int f[100][100];
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= n; i++)
    {
        f[i][i] = i; // tao bang
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[f[i][j - 1]] < a[j])
                f[i][j] = f[i][j - 1];
            else
                f[i][j] = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        int L = query[i].L, R = query[i].R;
        cout << a[f[L][R]] << endl;
    }
}