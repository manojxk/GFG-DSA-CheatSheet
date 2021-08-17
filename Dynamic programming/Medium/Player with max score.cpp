#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<long long>> dp;
    long long optimalStrategyOfGame(int *arr, vector<vector<long long>> &t, int i, int j)
    {
        if (i == j)
        {
            return t[i][j] = arr[i];
        }
        if (j == i + 1)
        {
            return t[i][j] = max(arr[i], arr[j]);
        }
        if (t[i][j] != -1)
            return t[i][j];
        long long val1 = arr[i] + min(optimalStrategyOfGame(arr, t, i + 2, j), optimalStrategyOfGame(arr, t, i + 1, j - 1));
        long long val2 = arr[j] + min(optimalStrategyOfGame(arr, t, i + 1, j - 1), optimalStrategyOfGame(arr, t, i, j - 2));
        return t[i][j] = max(val1, val2);
    }
    long long maximumAmount(int arr[], int n)
    {
        vector<vector<long long>> t(n, vector<long long>(n, -1));
        return optimalStrategyOfGame(arr, t, 0, n - 1);
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(a, n) << endl;
    }
    return 0;
}






int optimalStrategyOfGame(int *arr, int n)
{

    int dp[n][n];

    for (int g = 0; g < n; ++g)
    {
        for (int i = 0, j = g; j < n; ++i, ++j)
        {
            if (g == 0)
            {
                dp[i][j] = arr[i];
            }
            else if (g == 1)
            {
                dp[i][j] = max(arr[i], arr[j]);
            }
            else
            {
                int val1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(val1, val2);
            }
        }
    }

    return dp[0][n - 1];
}