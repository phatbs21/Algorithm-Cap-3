#include <bits/stdc++.h>
using namespace std;
//░█████╗░███╗░░██╗██████╗░████████╗██╗░█████╗░
//██╔══██╗████╗░██║██╔══██╗╚══██╔══╝██║██╔══██╗
//███████║██╔██╗██║██████╔╝░░░██║░░░██║██║░░██║
//██╔══██║██║╚████║██╔═══╝░░░░██║░░░██║██║░░██║
//██║░░██║██║░╚███║██║░░░░░░░░██║░░░██║╚█████╔╝
//╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░░░░░░░╚═╝░░░╚═╝░╚════╝░
#define ll long long int
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
#define MOD 1000000007
#define N 100005
vector<vector<int>> a(100005);
int n, m;
vector<int> num(N, 0), low(N, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> query;
    int q;
    cin >> q;
    query.assign(q, 0);
    for (auto &i : query)
    {
        cin >> i;
    }
    sort(query.begin(), query.end());
}
