#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string str)
{
    int count = 0;
    int n = str.size();
    bool dp[n][n];
    unordered_set<string> uset;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                if (str[i] == str[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (str[i] == str[j] and dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            if (dp[i][j] == true)
                {
                    uset.insert(str.substr(i,j-i+1));
                }
        }
    }
    return uset.size();
}
