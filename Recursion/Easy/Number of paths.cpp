long long numberOfPaths(int m, int n)
{
    if (m == 1 or n == 1)
        return 1;
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
}

long long numberOfPaths(int m, int n)
{
    int dp[m + 1][n + 1] = {{0}};

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                dp[i][j] = 1;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}