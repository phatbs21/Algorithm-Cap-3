#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("volleyball.inp", "r", stdin);
    freopen("volleyball.out", "w", stdout);

    int t;
    cin >> t;
    for (int l = 1; l < t; l++)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (x < k && y < k)
        {
            if (x > y)
                cout << k - x << " ";
            else if (y > x)
                cout << k - y << " ";
            else if (x == y)
            {
                if (x - 1 == k)
                    cout << k - x + 1 << " ";
                else if (x - 2 == k)
                    cout << k - x + 2 << " ";
                else
                    cout << k - x << " ";
            }
        }
        else if (x == k && y == k)
        {
            cout << 2 << " ";
        }
        else if (x > k && y <= k)
        {
            if (x - y == 1)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        else if (y > k && x <= k)
        {
            if (y - x == 1)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        else if (x > k && y > k)
        {
            if (x == y)
                cout << 2 << " ";
            else if (x - 1 == y || y - 1 == x)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
    }
    int k, x, y;
    cin >> k >> x >> y;
    if (x < k && y < k)
    {
        if (x > y)
            cout << k - x;
        else if (y > x)
            cout << k - y;
        else if (x == y)
        {
            if (x - 1 == k)
                cout << k - x + 1;
            else if (x - 2 == k)
                cout << k - x + 2;
            else
                cout << k - x;
        }
    }
    else if (x == k && y == k)
    {
        cout << 2;
    }
    else if (x > k && y <= k)
    {
        if (x - y == 1)
            cout << 1;
        else
            cout << 0;
    }
    else if (y > k && x <= k)
    {
        if (y - x == 1)
            cout << 1;
        else
            cout << 0;
    }
    else if (x > k && y > k)
    {
        if (x == y)
            cout << 2;
        else if (x - 1 == y || y - 1 == x)
            cout << 1;
        else
            cout << 0;
    }
}
