// https://practice.geeksforgeeks.org/problems/valid-substring0624/1
//Longest Valid Parentheses

int longestValidParentheses(string s)
{
    int left = 0, right = 0, maxlength = 0;
    //left to right
    for (char c : s)
    {
        if (c == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            maxlength = max(maxlength, 2 * left);
        }
        if (right > left)
        {
            left = right = 0;
        }
    }
    left = right = 0;
    //right to left
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            maxlength = max(maxlength, 2 * left);
        }
        if (right < left)
        {
            left = right = 0;
        }
    }
    return maxlength;
}
