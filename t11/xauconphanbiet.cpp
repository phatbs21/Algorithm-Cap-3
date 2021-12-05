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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    //  freopen("xauconphanbiet.inp", "r", stdin);
    // freopen("xauconphanbiet.out", "w", stdout);
#else
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        map<string, int> f;
        int flag = true;
        int dem = 0;
        for (int j = 0; j <= n - i; j++)
        {
            string s1 = s.substr(j, i);
            //cout << s1 << " ";
            if (f[s1] == 1)
            {
                flag = false;
                dem++;
            }
            f[s1]++;
        }
        //cout << dem << "\n";
        if (flag == false)
        {
            continue;
        }
        else
        {
            cout << i;
            break;
        }
    }
}
