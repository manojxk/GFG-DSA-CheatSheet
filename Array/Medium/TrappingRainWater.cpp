// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
    int maxl[n] = {-1};
    int maxr[n] = {-1};
    maxl[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxl[i] = max(arr[i], maxl[i - 1]);
    }
    maxr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxr[i] = max(arr[i], maxr[i + 1]);
    }
    int res = 0;
    int water[n];
    for (int i = 0; i < n; i++)
    {
        water[i] = min(maxl[i], maxr[i]) - arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        res += water[i];
    }
    return res;
}

// Driver code
int main()
{
    int arr[] = {0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n);

    return 0;
}
