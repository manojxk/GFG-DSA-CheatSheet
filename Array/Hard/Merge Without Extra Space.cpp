#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int x = n - 1, y = 0;
    while (x >= 0 && y < m)
    {
        if (arr1[x] > arr2[y])
        {
            swap(arr1[x], arr2[y]);
            x--;
            y++;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
