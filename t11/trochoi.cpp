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
#define se second.first
#define th second.second
#define pb push_back
int xuli(string s)
{
    int n = 0;
    for (int i = 0; i < (int)s.length(); i++)
        if (s[i] <= '9' && s[i] >= '0')
        {
            n++;
        }
    return n;
}
bool cmp(pair<string, pair<int, int>> s1, pair<string, pair<int, int>> s2)
{
    return ((s1.se < s2.se) || (s1.se == s2.se && s1.th < s2.th));
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("TROCHOI.out", "w", stdout);
    int n;
    cin >> n;
    cin.ignore();
    pair<string, pair<int, int>> s[10005];
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s[i].fi);
        s[i].th = i;
        s[i].se = xuli(s[i].fi);
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << s[i].fi << "\n";
    }
}
