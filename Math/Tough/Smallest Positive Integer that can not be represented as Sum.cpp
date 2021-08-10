

#include <bits/stdc++.h>
using namespace std;

long long smallestpositive(vector<long long> a, int n)
{
    // code here
    sort(a.begin(), a.end());
    long long res = 1;
    for (int i = 0; i < n and a[i] <= res; i++)
    {
        res += a[i];
    }
    return res;
}
