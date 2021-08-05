#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int m)
{

    int i = 0, j = 0;
    int count = 0, ans = 0, len;

    while (j < n)
    {
        if (a[j] == 0)
        {
            count++;
        }
        
        while (count > m)
        {
            if (a[i] == 0)
            {
                count--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    cout << solve(arr, 11, 2);
}