#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2)
{
    //cout << s1 << " " << s2 << endl;
    map<int, bool> a, b;
    for (int i = 0; i < s1.length(); i++)
        a[s1[i]] = true;
    for (int i = 0; i < s2.length(); i++)
        b[s2[i]] = true;
    for (int i = 48; i <= 57; i++)
        if (a[i] != b[i])
        {
            return false;
        }
    return true;
}
int main()
{
#if ONLINE_JUDGE
    freopen("digits.inp", "r", stdin);
    freopen("digits.out", "w", stdout);
#endif
    string x, y;
    cin >> x >> y;
    map<int, bool> a, b;
    for (int i = 0; i < x.length(); i++)
        a[x[i]] = true;
    for (int i = 0; i < y.length(); i++)
        b[y[i]] = true;

    int flag = 0;
    for (int i = 48; i <= 57; i++)
        if (a[i] != b[i])
        {
            flag++;
        }
    if (flag == 0)
    {
        cout << "friends";
        return 0;
    }
    for (int i = 0; i < x.length() - 1; i++)
    {
        string xx = x;
        xx[i] = x[i] + 1;
        xx[i + 1] == x[i + 1] - 1;
        if (x[i] < 48 or x[i] > 57 or x[i + 1] < 48 or x[i + 1] > 57)
            if (check(xx, y) == true)
            {
                cout << "almost friends";
                return 0;
            }
        xx[i] = x[i] - 1;
        xx[i + 1] == x[i + 1] + 1;
        if (x[i] < 48 or x[i] > 57 or x[i + 1] < 48 or x[i + 1] > 57)
            if (check(xx, y) == true)
            {
                cout << "almost friends";
                return 0;
            }
    }
    for (int i = 0; i < y.length() - 1; i++)
    {
        string yy = y;
        yy[i] = y[i] + 1;
        yy[i + 1] == y[i + 1] - 1;
        if (y[i] < 48 or y[i] > 57 or y[i + 1] < 48 or y[i + 1] > 57)
            if (check(yy, x) == true)
            {
                cout << "almost friends";
                return 0;
            }
        yy[i] = y[i] - 1;
        yy[i + 1] == y[i + 1] + 1;
        if (y[i] < 48 or y[i] > 57 or y[i + 1] < 48 or y[i + 1] > 57)
            if (check(yy, x) == true)
            {
                cout << "almost friends";
                return 0;
            }
    }
    /**for (int i = 0; i < x.length() - 1; i++)
    {
        string s1;
        s1.push_back(x[i]);
        s1.push_back(x[i + 1]);
        string s0;
        s0.push_back(x[i] - 1);
        s0.push_back(x[i + 1] + 1);
        string s3;
        s3.push_back(x[i] + 1);
        s3.push_back(x[i + 1] - 1);
        if (s3[0] < 48 || s3[0] > 57)
            s3 = "xx";
        if (s0[0] < 48 || s0[0] > 57)
            s0 = "xx";
        cout << s1 << " " << s0 << " " << s3 << endl;
        for (int j = 0; j < y.length() - 1; j++)
        {
            if (j == 0)
            {
                if (s1[0] == 48 || s0[0] == 48 || s3[0] == 48)
                    continue;
            }
            string s2;
            s2.push_back(y[j]);
            s2.push_back(y[j + 1]);
            string xx = x, yy = y;
            if (s2 == s1)
            {
                if (check(xx, yy) == true)
                {
                    cout << "almost friends";
                    return 0;
                }
            }
            if (s2 == s0)
            {

                yy[j] = s0[0], yy[j + 1] = s0[1];
                if (check(xx, yy) == true)
                {
                    cout << "almost friends";
                    return 0;
                }
            }
            if (s2 == s3)
            {

                yy[j] = s3[0], yy[j + 1] = s3[1];
                if (check(xx, yy) == true)
                {
                    cout << "almost friends";
                    return 0;
                }
            }
        }
    }**/
    cout << "nothing";
}
