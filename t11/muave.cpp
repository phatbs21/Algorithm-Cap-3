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
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int dem = 0;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            dem++;
        }
        else
        {
            dem = 0;
        }
        a[i] = dem;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        if (a[i + 1] > 0)
            a[i] = 0;
    }
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
    if (a[1] == 0)
    {
        cout << 0;
        return 0;
    }
    int i = 1, temp;
    while (a[i] != 0)
    {
        temp = a[i];
        i++;
    }
    cout << temp;
}
