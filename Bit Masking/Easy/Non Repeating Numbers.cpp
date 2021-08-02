// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
// https://youtu.be/pnx5JA9LNM4
int PositionRightmostSetbit(int n)
{
    int position = 1;
    int m = 1;
    while (!(n & m))
    {
        m = m << 1;
        position++;
    }
    return position - 1;
}
vector<int> singleNumber(vector<int> nums)
{
    int xorr = 0;
    for (int val : nums)
        xorr = xorr ^ val;
    int bits = 1 << PositionRightmostSetbit(xorr); 
    int x = 0;
    int y = 0;
    for (int val : nums)
    {
        if ((val & bits) == 0)
            x = x ^ val;
        else
            y = y ^ val;
    }
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin(), ans.end());
    return ans;
}