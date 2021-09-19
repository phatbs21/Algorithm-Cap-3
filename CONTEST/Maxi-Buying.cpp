#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n > 191)
    {
        cout << ":(";
    }
    if (n == 191)
    {
        cout << "so-so";
    }
    if (n < 191)
        cout << "Yay!";
        
}