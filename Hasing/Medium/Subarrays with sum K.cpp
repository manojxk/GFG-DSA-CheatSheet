
#include <bits/stdc++.h>
using namespace std;

int findSubArraySum(int Arr[], int N, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        sum += Arr[i];
        if (mp.find(sum - k) != mp.end())
        {
            res += mp[sum - k];
        }
        mp[sum]++;
    }
    return res;
}
