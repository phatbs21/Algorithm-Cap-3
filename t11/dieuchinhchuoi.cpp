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
void xuli()
{
    int n;
    cin >> n;
    vector<string> s;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, temp);
        s.pb(temp);
    }
    map<char, int> q;
    for (int i = 0; i < n; i++)
    {
        string s_temp = s[i];
        for (int j = 0; j < s_temp.size(); j++)
        {
            q[s_temp[i]]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << char(97 + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << q[char(i + 97)] << " ";
        if (q[char(i + 97)] % n != 0)
        {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        xuli();
    }
}
