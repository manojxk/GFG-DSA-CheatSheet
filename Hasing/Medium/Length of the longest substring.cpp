#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

int longestUniqueSubsttr(string s)
{
    //code
    unordered_set<char> set;
    int i = 0, j = 0, ans = 0, n = s.size();
    while (i < n && j < n)
    {
        if (set.find(s[j]) == set.end())
        {
            set.insert(s[j++]);
            ans = max(ans, j - i);
        }
        else
        {
            set.erase(s[i++]);
        }
    }
    return ans;
}
