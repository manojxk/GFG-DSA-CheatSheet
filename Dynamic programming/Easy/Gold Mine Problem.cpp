#include <bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == m - 1)
            {
                dp[i][j] = M[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = M[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else if (i == n - 1)
            {
                dp[i][j] = M[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else
            {
                dp[i][j] = M[i][j] + max({dp[i][j + 1], dp[i + 1][j + 1], dp[i - 1][j + 1]});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i][0]);
    }
    return ans;
}
