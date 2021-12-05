// C++ program for implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;
int dem = 0;
bool check(int x, int y)
{
    dem++;
    if (x < y)
        return true;
    else
        return false;
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = {9, 5, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n,check);
    cout << "Sorted array: \n";
    printArray(arr, n);
    cout << dem;
    return 0;
}

// This code is contributed by rathbhupendra
