#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;
#define fr(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define frl(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define frr(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define cin f1
#define cout f2
ifstream f1("sumation.inp");
ofstream f2("sumation.out");
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> a;
    int n, temp1 = 0, tong = 0;
    double tong2 = 0;
    cin >> n;
    frl(i, 1, n)
    {
        int temp;
        cin >> temp;
        tong += temp;
        a.push(temp);
    }
    while (temp1 != tong)
    {
        temp1 = a.top();
        a.pop();
        temp1 += a.top();
        a.pop();
        tong2 = tong2 + temp1 * 0.05;
        a.push(temp1);
    }
    cout << setprecision(2) << fixed << tong2;
}
