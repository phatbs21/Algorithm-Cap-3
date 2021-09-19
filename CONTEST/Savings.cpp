#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int64_t tong = 0;
    int i = 0;
    while (n > tong)
    {
        i++;
        tong += i;
    }
    cout << i;
}