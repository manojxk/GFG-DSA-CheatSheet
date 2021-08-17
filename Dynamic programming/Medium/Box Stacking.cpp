// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

static bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return (a.first.first * a.first.second) > (b.first.first * b.first.second);
}
int maxHeight(int height[], int width[], int length[], int n)
{

    int dp[10000];
    vector<pair<pair<int, int>, int>> v;
    memset(dp, 0, sizeof(dp));
    v.clear();
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        a = height[i];
        b = width[i];
        c = length[i];
        v.push_back({{a, b}, c});
        v.push_back({{b, a}, c});
        v.push_back({{a, c}, b});
        v.push_back({{c, a}, b});
        v.push_back({{b, c}, a});
        v.push_back({{c, b}, a});
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++)
    {
        dp[i] = v[i].second;
        for (int j = 0; j < i; j++)
        {
            if (v[i].first.first < v[j].first.first and v[i].first.second < v[j].first.second)
            {
                dp[i] = max(dp[i], dp[j] + v[i].second);
            }
        }
    }

    return *max_element(dp, dp + 10000);
}
