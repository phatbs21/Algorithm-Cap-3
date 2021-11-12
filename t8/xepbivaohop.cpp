#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 1
#define ll long long
#define pb push_back
#define fi first
#define se second

#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif // ONLINE_JUDGE

ll n;

void init()
{
    cin>>n;
}

string tos(ll x)
{
    ostringstream k;
    k<<x;
    return k.str();
}

bool check(ll x)
{
   // string s=tos(x);
    ll cur1=1,cur2=0;
    while (x>0)
    {
        cur1*=(x%10);
        cur2+=(x%10);
        x=x/10;
    }
    return (cur1%cur2==0) ? true : false;
}

void solve()
{
    ll i=1;
    while (n>0)
    {
        if (check(i))
            n--;
        i++;
    }
    cout<<i-1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
