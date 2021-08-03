//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    int n = strs.size();
    if (n == 0)
        return ans;
    unordered_map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
