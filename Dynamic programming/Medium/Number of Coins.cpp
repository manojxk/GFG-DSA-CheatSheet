class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for (int coin : coins)
            {
                if (coin <= i and dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};