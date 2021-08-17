#include <bits/stdc++.h>
using namespace std;

int solve(int A[], int n, int val)
{
    if (n == 0)
        return val;
    int t = solve(A, n - 1, val ^ A[n - 1]);
    int p = solve(A, n - 1, val);
    return max(t, p);
}
int maxSubarrayXOR(int A[], int n)
{
    return solve(A, n, 0);
}