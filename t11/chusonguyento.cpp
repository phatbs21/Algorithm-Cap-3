#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll int64_t
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
vector<int> d(10000000, true);
void nto(int n)
{
    d[0] = d[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (d[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                d[j] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    nto(100009);
    string s;
    cin >> s;
    vector<int> a(s.length() + 1, 0);
    for (int i = 1; i <= s.length(); i++)
    {
        a[i] = s[i - 1] - '0';
    }
    map<int, int> q;
    for (int i = 1; i <= s.length(); i++)
    {
        if (q[a[i]] == 0 && d[a[i]])
        {
            cout << a[i] << " ";
        }
        q[a[i]]++;
    }
}
