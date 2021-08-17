#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[201][201];
    int solve(string p, string s, int i, int j)
    {
        if (i == -1 && j == -1)
            return 1;
        if (i == -1)
            return 0;
        if (j == -1)
        {
            while (i >= 0)
            {
                if (p[i] != '*')
                    return 0;
                i--;
            }
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[i] == s[j] or p[i] == '?')
            return dp[i][j] = solve(p, s, i - 1, j - 1);
        if (p[i] == '*')
        {
            int op1 = solve(p, s, i - 1, j);
            int op2 = solve(p, s, i, j - 1);
            return dp[i][j] = op1 || op2;
        }

        return dp[i][j] = 0;
    }
    int wildCard(string p, string s)
    {
        memset(dp, -1, sizeof(dp));
        return solve(p, s, p.size() - 1, s.size() - 1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}
// } Driver Code Ends