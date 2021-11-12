#include <bits/stdc++.h>
using namespace std;
/*

██╗░░░██╗██╗░░░  ██████╗░██╗░░░██╗░█████╗░░█████╗░  ██████╗░░█████╗░██╗
██║░░░██║██║░░░  ██╔══██╗██║░░░██║██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗██║
██║░░░██║██║░░░  ██║░░██║██║░░░██║██║░░██║██║░░╚═╝  ██████╔╝██║░░██║██║
██║░░░██║██║██╗  ██║░░██║██║░░░██║██║░░██║██║░░██╗  ██╔══██╗██║░░██║██║
╚██████╔╝██║╚█║  ██████╔╝╚██████╔╝╚█████╔╝╚█████╔╝  ██║░░██║╚█████╔╝██║
░╚═════╝░╚═╝░╚╝  ╚═════╝░░╚═════╝░░╚════╝░░╚════╝░  ╚═╝░░╚═╝░╚════╝░╚═╝

████████╗██╗░░██╗░█████╗░███╗░░██╗██╗░░██╗  ██████╗░██████╗░░█████╗░
╚══██╔══╝██║░░██║██╔══██╗████╗░██║██║░██╔╝  ██╔══██╗██╔══██╗██╔══██╗
░░░██║░░░███████║███████║██╔██╗██║█████═╝░  ██████╦╝██████╔╝██║░░██║
░░░██║░░░██╔══██║██╔══██║██║╚████║██╔═██╗░  ██╔══██╗██╔══██╗██║░░██║
░░░██║░░░██║░░██║██║░░██║██║░╚███║██║░╚██╗  ██████╦╝██║░░██║╚█████╔╝
░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝  ╚═════╝░╚═╝░░╚═╝░╚════╝░
*/
#define ll long long int
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
int dem = 0;
/*
void xuli(int i, string s)
{
    if (i == (int)s.length() - 1)
    {
        dem++;
        return;
    }
    char previous = '!';
    for (int j = i; j < (int)s.length(); j++)
    {
        string s_temp = s;
        if ((j > i && s_temp[i] == s_temp[j]) || (previous != '!' && previous == s[j]))
            continue;
        swap(s_temp[i], s_temp[j]);
        previous = s[j];
        xuli(i + 1, s_temp);
    }
}*/
int f[1000];
void tinhtoan(int x, int &so2, int &so5)
{
    while (x % 5 == 0)
    {
        so5++;
        x /= 5;
    }
    while (x % 2 == 0)
    {
        so2++;
        x /= 2;
    }
}
int tinh(string s)
{
    string s1;
    int so2 = 0, so5 = 0;
    int n = s.length();
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        tinhtoan(i, so2, so5);
    }
    for (int i = 0; i < n; i++)
    {
        f[s[i] - 'a']++;
        if (f[s[i] - 'a'] == 1)
            s1.pb(s[i]);
    }
    n = s1.length();
    map<char, int> ditconme;
    for (int i = 0; i < n; i++)
    {
        int so2_temp = 0, so5_temp = 0;
        char q = s1[i];
        for (int j = 1; j <= f[q - 'a']; j++)
        {
            tinhtoan(j, so2_temp, so5_temp);
        }
        so2 -= so2_temp;
        so5 -= so5_temp;
    }
    return min(so2, so5);
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
    int klasjdaasdkjlqweqweiouqeiuqwoieqwuoeiqwouieqwkqwjeopadi;
    cin >> klasjdaasdkjlqweqweiouqeiuqwoieqwuoeiqwouieqwkqwjeopadi;
    cin.ignore();
    string s;
    getline(cin, s);
    //sort(s.begin(), s.end());
    //xuli(0, s);
    // cout << dem << " ";
    dem = tinh(s);
    cout << max(dem, 0);
    //demSo0(dem);
}
