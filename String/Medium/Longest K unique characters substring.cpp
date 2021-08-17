#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    if (k > s.size())
        return -1;
    unordered_set<char> uset(s.begin(), s.end());
    if (uset.size() < k)
        return -1;
    int i = 0, j = 0, ans = 0;
    unordered_map<char, int> mp;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
        }
        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}
