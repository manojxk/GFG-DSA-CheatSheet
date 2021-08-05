// https://practice.geeksforgeeks.org/problems/triplets-with-sum-with-given-range/1/#:~:text=Given%20an%20array%20Arr%5B%5D,range%20%5B7%2C%2011%5D.

#include <bits/stdc++.h>
using namespace std;

int countTripletsLessThan(int arr[], int n, int val)
{
    sort(arr, arr + n);
    int ans = 0;
    int j, k;
    int sum;

    // Fix the first element
    for (int i = 0; i < n - 2; i++)
    {

        // Initialize other two elements as
        // corner elements of subarray arr[j+1..k]
        j = i + 1;
        k = n - 1;

        // Use Meet in the Middle concept.
        while (j < k)
        {
            sum = arr[i] + arr[j] + arr[k];

            // If sum of current triplet
            // is greater, then to reduce it
            // decrease k.
            if (sum > val)
                k--;

            // If sum is less than or equal
            // to given value, then add
            // possible triplets (k-j) to result.
            else
            {
                ans += (k - j);
                j++;
            }
        }
    }

    return ans;
}

int countTriplets(int arr[], int n, int a, int b)
{

    int res;
    // Find count of triplets having sum less
    // than or equal to b and subtract count
    // of triplets having sum less than or
    // equal to a-1.
    res = countTripletsLessThan(arr, n, b) -
          countTripletsLessThan(arr, n, a - 1);

    return res;
}

// Driver Code
int main()
{
    int arr[] = {2, 7, 5, 3, 8, 4, 1, 9};
    int n = sizeof arr / sizeof arr[0];
    int a = 8, b = 16;
    cout << countTriplets(arr, n, a, b) << endl;
    return 0;
}
