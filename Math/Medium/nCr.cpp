int nCr(int n, int r)
{
    if (n < r)
        return 0;
    vector<vector<int>> ans(n + 1);
    int mod = 1000000007;
    for (int i = 0; i <= n; i++)
    {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i - 1][j - 1] % mod + ans[i - 1][j] % mod;
        }
    }
    return ans[n][r] % mod;
}