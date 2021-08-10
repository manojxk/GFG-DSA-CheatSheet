
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int k, int mx)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mx)
        {
            student++;
            sum = arr[i];
        }
        if (student > k)
            return false;
    }
    return true;
}

int findPages(int arr[], int n, int k)
{
    long long sum = 0;
    if (n < k)
        return -1;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int start = *max_element(arr, arr + n);
    int end = sum;
    int result = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, k, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return result;
}
