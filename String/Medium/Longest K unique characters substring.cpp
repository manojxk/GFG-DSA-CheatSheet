int longestKSubstr(string s, int k)
{
    if (k > s.size())
    {
        return -1;
    }
    unordered_map<char, int> temp;
    for (auto it : s)
    {
        temp[it]++;
    }
    if (k > temp.size())
    {
        return -1;
    }
    unordered_map<char, int> mp;
    int mx = INT_MIN;
    int i = 0, j = 0;
    int n = s.size();
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
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
            j++;
        }
    }
    return mx;
}
