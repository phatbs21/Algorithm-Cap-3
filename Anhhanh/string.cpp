#include <bits/stdc++.h>
using namespace std;
int x, y, k, so[26];
vector<string> kq;
string cur;
void backTrack()
{
    if (cur.size() >= x)
    {
        kq.push_back(cur);
        if (kq.size() == k)
            return;
    }
    
}
int main()
{
    while (cin >> x >> y >> k)
    {
        for (int i = 0; i < 26; i++)
            cin >> so[i];
        bool flag = false;
        for (int i = 0; i < 26; i++)
            flag = true;
        if (flag == true && x > y)
        {
            cout << "NO"
                 << "\n";
            continue;
        }
        kq.clear();
        cur.clear();
    }
}