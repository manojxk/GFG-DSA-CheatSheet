
int lengthOfLongestSubstring(string s)
{
    unordered_set<char> _set;
    int n = s.size();
    int ans = 0, begin = 0, end = 0;
    while (end < n)
    {
        if (_set.find(s[end]) == _set.end())
        {
            _set.insert(s[end]);
            end++;
            ans = max(ans, end - begin);
        }
        else
        {
            _set.erase(s[begin++]);
        }
    }
    return ans;
}
