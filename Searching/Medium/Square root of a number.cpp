class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        // Your code goes here
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        long long int l = 1, r = x, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (m * m == x)
                return m;
            if (m * m > x)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
};