#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int a[], int n, int x)
{
    sort(a, a + n);
    int j = 0, k = 0, target = 0;
    for (int i = 0; i < n - 2; i++)
    {

        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            if (a[i] + a[j] + a[k] == x)
                return true;
            else if (a[i] + a[j] + a[k] > x)
                k--;
            else
                j++;
        }
    }
    return false;
}
