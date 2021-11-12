#include <bits/stdc++.h>
using namespace std;
bool checkY(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}
int thang[13] = {0, 31, 100, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int so212[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int main()
{
// tinh ngay thang
    freopen("olympics.inp", "r", stdin);
    freopen("olympics.out", "w", stdout);
    string s;
    cin >> s;
    int y = 0, m = 0, d = 0;
    for (int i = 0; i < 4; i++)
    {
        y = y * 10 + (s[i] - 48);
    }
    for (int i = 5; i <= 6; i++)
    {
        m = m * 10 + (s[i] - 48);
    }
    for (int i = 8; i <= 9; i++)
    {
        d = d * 10 + (s[i] - 48);
    }
    int dem = 0;
    while (d != 23 || m != 7 || y != 2021)
    {
        dem++;
        if (d == thang[m] && m != 2 && m != 12)
        {
            m++;
            d = 1;
        }
        else if (m == 2 && ((checkY(y) == true && d == 29) || (checkY(y) == false && d == 28)))
        {
            m++;
            d = 1;
        }
        else if (m == 12 && thang[m] == d)
        {
            m = 1;
            y++;
            d = 1;
        }
        else
        {
            d++;
        }
        //cout << d << " " << m << " " << y << ' ' << dem << endl;
    }
    cout << dem;
}