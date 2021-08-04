string Reduced_String(int k, string s)
{
    string ans = "";
    if (k == 1)
        return ans;
    stack<pair<char, int>> stk;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        //three chances:-
        //1)stack can be empty
        //2)top is equal to s[i]
        //3)stack is not empty with top is also not equal to s[i]
        if (stk.empty())
        {
            count = 1;
            stk.push({s[i], count});
        }
        else if (stk.top().first == s[i])
        {
            count = stk.top().second + 1;
            stk.push({s[i], count});
            if (count == k)
            {
                while (count--)
                    stk.pop();
            }
        }
        else
        {
            count = 1;
            stk.push({s[i], count});
        }
    }
    while (!stk.empty())
    {
        ans += stk.top().first;
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}