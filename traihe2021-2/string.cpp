#include <bits/stdc++.h>
using namespace std;
int x, y, k;
vector<int> c(26, 0);
void subtask1()
{
    int dem = 0;

    for (int i = 0; i <= 25; i++)
    {
        for (int j = 1; j <= c[i] && dem < x; j++)
        {
            if (dem == 0)
                cout << "YES"
                     << " \n";
            cout << char(i + 97);
            dem++;
        }
    }
    if (dem == 0 || dem < x)
        cout << "NO";
    cout << "\n";
}
int giaiThua(int n)
{
    int giai_thua = 1;
    for (int i = 1; i <= n; i++)
        giai_thua *= i;
    return giai_thua;
}

void subtask2()
{
    int flag = 0;
    vector<int> z;
    cout << "YES"
         << "\n";
    for (int i = 0; i < 26; i++)
    {
        if (c[i] > 0)
        {
            z.push_back(i);
        }
        else
            break;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < z.size(); j++)
        {
            cout << char(z[j] + 97);
        }
        cout << " ";
        next_permutation(z.begin(), z.end());
    }
    cout << "\n";
}
int main()
{
    freopen("string.inp", "r", stdin);
    freopen("string.out", "w", stdout);
    while (cin >> x >> y >> k)
    {
        int max = INT_MIN;
        for (auto &i : c)
        {
            cin >> i;
            if (i > max)
                max = i;
        }
        int tong = accumulate(c.begin(), c.end(), 0);
        if (k == 1)
            subtask1();
        else if (x == y && tong == x && (max == 1 || max == 0))
        {
            if (k > giaiThua(x))
                cout << "NO"
                     << "\n";
            subtask2();
        }
        else
        {
            cout << "NO\n";
        }
    }
}