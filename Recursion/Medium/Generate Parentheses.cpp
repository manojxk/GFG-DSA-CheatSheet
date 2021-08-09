
vector<string> result;
void solve(int n, string ans, int open, int close)
{
    if (ans.size() == 2 * n)
    {
        result.push_back(ans);
        return;
    }
    if (open < n)
        solve(n, ans + "(", open + 1, close);
    if (open > close)
        solve(n, ans + ")", open, close + 1);
}
vector<string> generateParenthesis(int n)
{
    solve(n, "", 0, 0);
    return result;
}
