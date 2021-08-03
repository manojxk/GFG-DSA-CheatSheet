// https://www.geeksforgeeks.org/value-to-be-subtracted-from-array-elements-to-make-sum-of-all-elements-equals-k/

// C++ implementation of the approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to return the amount of wood
// collected if the cut is made at height m
int woodCollected(int height[], int n, int m)
{
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (height[i] - m <= 0)
            break;
        sum += (height[i] - m);
    }

    return sum;
}

// Function that returns Height at
// which cut should be made
int collectKWood(int height[], int n, int k)
{
    // Sort the heights of the trees
    sort(height, height + n);

    // The minimum and the maximum
    // cut that can be made
    int low = 0, high = height[n - 1];

    // Binary search to find the answer
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        // The amount of wood collected
        // when cut is made at the mid
        int collected = woodCollected(height, n, mid);

        // If the current collected wood is
        // equal to the required amount
        if (collected == k)
            return mid;

        // If it is more than the required amount
        // then the cut needs to be made at a
        // height higher than the current height
        if (collected > k)
            low = mid + 1;

        // Else made the cut at a lower height
        else
            high = mid - 1;
    }

    return -1;
}

// Driver code
int main()
{

    int height[] = {1, 2, 1, 2};
    int n = sizeof(height) / sizeof(height[0]);
    int k = 2;

    cout << collectKWood(height, n, k);

    return 0;
}
