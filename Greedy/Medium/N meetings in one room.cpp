#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int maxMeetings(int s[], int f[], int n)
{
    vector<pair<int, int>> act;
    for (int i = 0; i < n; i++)
    {
        act.push_back({s[i], f[i]});
    }
    sort(act.begin(), act.end(), comp);
    int ans = 1;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (act[j].first > act[i].second)
        {
            ans++;
            i = j;
        }
    }
    return ans;
}
