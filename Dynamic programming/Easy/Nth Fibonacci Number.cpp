long long int nthFibonacci(long long int n)
{
    // code here
    long long int *dp = new long long int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (long long int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
}