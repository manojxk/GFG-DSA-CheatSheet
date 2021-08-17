class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.size();
        bool dp[n][n];
        int start, end;
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
                    if (s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if (s[i] == s[j] and dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                if (dp[i][j])
                {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};