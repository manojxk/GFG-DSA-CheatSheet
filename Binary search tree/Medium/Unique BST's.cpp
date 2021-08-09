#include <bits/stdc++.h>
using namespace std;
#define mod (int)(1e9 + 7)
long long catalan_number(int n)
{

    long long catalan[n + 1];
    catalan[0] = 1;
    catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catalan[i] += (catalan[j] % mod) * (catalan[i - j - 1] % mod) % mod;
        }
    }
    return catalan[n] % mod;
}
int numTrees(int N)
{
    return catalan_number(N);
}
