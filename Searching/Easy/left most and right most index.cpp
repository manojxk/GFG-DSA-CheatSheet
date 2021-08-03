
vector<int> searchRange(vector<int> &nums, int t)
{
    int l = 0, h = nums.size() - 1;
    int m = 0;
    int f = -1, s = -1;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (nums[m] == t)
        {
            f = m;
            h = m - 1;
        }
        else if (nums[m] < t)
            l = m + 1;
        else
            h = m - 1;
    }
    l = 0;
    h = nums.size() - 1;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (nums[m] == t)
        {
            s = m;
            l = m + 1;
        }
        else if (nums[m] < t)
            l = m + 1;
        else
            h = m - 1;
    }
    return {f, s};
}
