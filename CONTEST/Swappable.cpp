#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    map<long long int, long long int> q;
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
        q[a[i]]++;
    }
    long long int tong = (n * (n - 1)) / 2;
    //    cout<<tong<<" ";
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (long long int i = 0; i < (long long int)a.size(); i++)
    {
        //cout << q[a[i]] << " ";
        if (q[a[i]] > 1)
        {
            tong = tong - ((q[a[i]] * (q[a[i]] - 1)) / 2);
        }
    }
    cout  << tong;
    //4 1 1 3 3 2 1 2 3
}