string fractionToDecimal(int n, int d)
{
    unordered_map<int, int> m;
    int q = n / d;
    string ans = to_string(q);
    int r = n % d;
    if (r == 0)
    {
        return ans;
    }
    else
    {
        ans += '.';
        while (r != 0)
        {
            if (m.find(r) != m.end())
            {
                int l = m[r];
                ans.insert(l, "(");
                ans += ")";
                break;
            }
            else
            {
                m[r] = ans.length();
                r *= 10;
                q = r / d;
                r = r % d;
                ans = ans + to_string(q);
            }
        }
    }

    return ans;
}