// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

long long findNth(long long n)
{
    int binaryNum[32];
    long long ans = 0;
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 9;
        n = n / 9;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        ans = ans * 10 + binaryNum[j];
    return ans;
}
