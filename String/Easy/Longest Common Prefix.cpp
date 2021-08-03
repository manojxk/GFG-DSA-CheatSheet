class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        int minLength = min(first.size(), last.size());
        int i = 0;
        while (i < minLength and first[i] == last[i])
            i++;
        return first.substr(0, i);
    }
};
//Sorting of string takes MAX*nlogn