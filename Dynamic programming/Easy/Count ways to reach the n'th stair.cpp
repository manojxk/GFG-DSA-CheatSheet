int countWays(int n)
{
    int a[n + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
    }
    return a[n] % 1000000007;
}