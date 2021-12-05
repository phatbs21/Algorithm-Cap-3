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
void matching(vector<pii> pos, vector<pii> neg, bool boypos)
{
    if (pos.empty() || neg.empty())
        return;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int j = 0;
    for (int i = 0; i < neg.size(); i++)
    {
        if (j < (int)pos.size() && pos[j].fi < neg[i].fi)
        {
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("couples.inp", "r", stdin);
    freopen("couples.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> boy(n);
    for (int i = 0; i < n; i++)
    {
        cin >> boy[i];
    }
    int m;
    cin >> m;
    vector<int> girl;
    for (int i = 0; i < n; i++)
    {
        cin >> girl[i];
    }
}
