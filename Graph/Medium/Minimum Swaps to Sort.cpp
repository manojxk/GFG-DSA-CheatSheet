
int minSwaps(vector<int> &nums)
{
    // Code here
    int cnt = 0;
    int n = nums.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < nums.size(); i++)
        v[i] = {nums[i], i};
    sort(v.begin(), v.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == v[i].second)
            continue;
        else
        {
            swap(v[i], v[v[i].second]);
            cnt++;
            i--;
        }
    }
    return cnt;
}
