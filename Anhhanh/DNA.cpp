#include <bits/stdc++.h>
using namespace std;
int tinh(char m, char n, string str1, string str2)
{
    char f[m + 1][n + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                f[i][j] = j;
            else if (j == 0)
                f[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
        }
    }
    return f[m][n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("adn.inp", "r", stdin);
    freopen("adn.out", "w", stdout);
#endif
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if (tinh(s1.length(), s2.length(), s1, s2) > 2)
        cout << "No";
    else
        cout << "Yes";
    return 0;
    /**
    map<char, char> q, e;
    for (int i = 0; i < s1.length(); i++)
    {
        q[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        e[s2[i]]++;
    }
    int dem = 0;
    for (int i = 0; i < 255; i++)
    {
        dem += abs(e[i] - q[i]);
    }
    if (s1.length() > s2.length() + 2 || s1.length() + 2 < s2.length() || dem > 4)
    {
        cout << "No";
        return 0;
    }
    if (tinh(s1.length(), s2.length(), s1, s2) > 2)
        cout << "No";
    else
        cout << "Yes";**/
}