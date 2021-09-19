#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<char, ll>> luu, luu2, res;
ll dem = 0, dem2 = 0;
string doi1, doi2;
void doi(string s1, string s2)
{
    bool danhdau = false;
    for (ll i = 0; i < s1.length(); i++)
    {
        if (s1[i] > 90)
        {
            danhdau = false;
            luu.push_back({s1[i], 0});
            dem++;
        }
        else
        {
            if (danhdau == false)
            {
                luu[dem - 1].second = s1[i] - 48;
                danhdau = true;
            }
            else
                luu[dem - 1].second = (s1[i] - 48) + luu[dem - 1].second * 10;
        }
    }
    for (ll i = 0; i < s2.length(); i++)
    {
        if (s2[i] > 90)
        {
            danhdau = false;
            luu2.push_back({s2[i], 0});
            dem2++;
        }
        else
        {
            if (danhdau == false)
            {
                luu2[dem2 - 1].second = s2[i] - 48;
                danhdau = true;
            }
            else
                luu2[dem2 - 1].second = (s2[i] - 48) + luu2[dem2 - 1].second * 10;
        }
    }
    dem--, dem2--;
}
void doilai()
{
    
}
void cong()
{
    cout << "@1: ";
    if (luu[dem].first == luu2[0].first)
    {
        for (ll i = 0; i < dem; i++)
        {
            cout << luu[i].first << luu[i].second;
        }
        cout << luu[dem].first << luu[dem].second + luu2[0].second;
        for (ll i = 1; i <= dem2; i++)
        {
            cout << luu2[i].first << luu2[i].second;
        }
    }
    else
    {
        for (ll i = 0; i <= dem; i++)
        {
            cout << luu[i].first << luu[i].second << "";
        }
        for (ll i = 0; i <= dem2; i++)
        {
            cout << luu2[i].first << luu2[i].second << "";
        }
    }
    cout << "\n";
}
string copy(int u, int v)
{
    if (v == -1)
    {
        v = 1;
        for (int i = 0; i < luu.size(); i++)
        {
            v += luu[i].second;
        }
        v -= u;
    }
    if (v == 0)
        return "";
    for (int i = 0, cnt = 0; i < luu.size(); i++)
    {
        if ((cnt += luu[i].second) >= u + 1)
        {
            res.push_back({luu[i].first, min(v, cnt - u)})
            {
                v -= luu[i].second;
            }
            break;
        }
    }

}
int main()
{
    string test;
    while (cin >> test)
    {
        dem = 0, dem2 = 0;
        luu.clear();
        luu2.clear();
        res.clear();
        string s, s1;
        cin >> s;
        if (test == "@1")
        {
            cin >> s1;
            doi(s, s1);
            cong();
            continue;
        }
        s1 = "";
        doi(s, s1);
        //inra();
        if (test == "@2")
        {
            int u, v;
            cin >> u >> v;
        }
    }
}
