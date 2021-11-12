#include <bits/stdc++.h>
using namespace std;
vector<int> a, f;

int ceilIndex(int i, int l, int r)
{
    while (r - l > 1) // nhét số giữa mà lớn hơn ở phần tử cuối
    {
        int m = (l + r) / 2;
        if (a[i] > f[m])
            l = m;
        else
            r = m;
    }
    return r;
}
int main()
{
    int n = 5;
    cin >> n;
    a.assign(n, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f.assign(a.size() + 2, 0);
    f[1] = a[1];
    int length = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= f[1]) // TH1: nếu a[i] nhỏ nhất trong các số cuối của danh sách thì bắt đầu mảng mới
            f[1] = a[i];
        else if (a[i] > f[length]) // TH2: Nếu a[i] lớn nhất trong các số cuối của danh sách thì mở rộng danh sách
            f[++length] = a[i];
        else //TH3: nếu a[i] ở giữa thì tìm danh sách có phần tử cuối lớn nhất < a[i] sao chép và mở rộng danh sách, loại bỏ các danh sách cùng độ dài với danh sách mới
             // v [i] sẽ trở thành ứng cử viên cuối cùng của một dãy con hiện có hoặc Vứt bỏ các phần tử lớn hơn trong tất cả LIS, để nhường chỗ cho các phần tử lớn hơn sắp tới so với v [i] (và cũng có thể, v [i] đã xuất hiện ở một trong các LIS, xác định vị trí và thay thế nó)
             // v[i] will become end candidate of an existing subsequence or Throw away larger elements in all LIS, to make room for upcoming greater elements than v[i] (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            f[ceilIndex(i, 1, length)] = a[i];
    }
    cout << length << "\n";
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
}
//        5
//        2 1 4 3 5
//