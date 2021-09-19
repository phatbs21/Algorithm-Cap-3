#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int chan = 0, le = 0;
        int k;
        cin >> k;
        for (int j = 0; j < k*2; j++)
        {
            int temp;
            cin >> temp;
            if (temp % 2 == 0)
                chan++;
            else
                le++;
        }
        if (chan == le)
        {
            cout << "Yes";
        }
        else
            cout << "No";
        cout << "\n";
    }
}