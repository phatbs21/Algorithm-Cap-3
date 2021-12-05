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
#define mp make_pair
typedef pair<int, int> pii;
vector<pair<int, int>> caoBoy, lunBoy, caoGirl, lunGirl, couples;
int match(vector<pair<int, int>> cao, vector<pair<int, int>> thap, bool kt)
{
    if (cao.size() == 0 || thap.size() == 0)
        return 0;
    sort(cao.begin(), cao.end());
    sort(thap.begin(), thap.end());
    int j = 0;
    for (int i = 0; i < thap.size(); i++)
    {
        if (j < cao.size() && cao[j].fi < thap[i].fi)
        {
            int x = cao[j].se, y = thap[i].se;
            if (kt == 0)
                swap(x, y);
            couples.pb(mp(x, y));
            j++;
        }
    }
}
void process()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            caoBoy.pb(mp(x, i));
        else
            lunBoy.pb(mp(-x, i));
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            caoGirl.pb(mp(x, i));
        else
            lunGirl.pb(mp(-x, i));
    }
    match(caoBoy, lunGirl, 1);
    match(caoGirl, lunBoy, 0);
    cout << couples.size() << "\n";
    for (int i = 0; i < couples.size(); i++)
        cout << couples[i].fi << " " << couples[i].se << "\n";
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
    process();
}
