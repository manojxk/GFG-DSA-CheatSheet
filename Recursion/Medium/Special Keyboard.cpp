

#include <bits/stdc++.h>
using namespace std;

long long int optimalKeys(int N)
{
    // code here
    if (N <= 6)
        return N;
    int res[N + 1];
    res[0] = -1;
    for (int i = 1; i <= 6; i++)
    {
        res[i] = i;
    }
    for (int n = 7; n <= N; n++)
    {
        res[n] = max({2 * res[n - 3], 3 * res[n - 4], 4 * res[n - 5]});
    }
    return res[N];
}
