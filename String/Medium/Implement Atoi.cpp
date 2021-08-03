int myAtoi(string s)
{
    int sign = 1;
    int i = 0;
    int n = s.size();

    while (i < n and s[i] == ' ')
        i++;
    if (i == n)
        return 0;

    if (s[i] == '-')
    {
        sign = 0;
        i++;
    }
    else if (s[i] == '+')
    {
        sign = 1;
        i++;
    }
    long long int ans = 0;
    while (s[i] >= '0' and s[i] <= '9')
    {
        ans = ans * 10;
        if (ans >= INT_MAX or ans <= INT_MIN)
            break;
        ans += (s[i] - '0');
        i++;
    }
    if (sign == 0)
    {
        ans = (-1) * ans;
    }
    if (ans <= INT_MIN)
        return INT_MIN;
    if (ans >= INT_MAX)
        return INT_MAX;
    return (int)ans;
}
