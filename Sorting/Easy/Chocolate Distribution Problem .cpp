
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        int end = 0, start = 0;
        int ans = INT_MAX;
        while (end < n)
        {
            // sum += a[end];
            if ((end - start + 1) < m)
            {
                end++;
            }
            else
            {
                int x = a[end] - a[start];
                ans = min(ans, x);
                start++;
                end++;
            }
        }
        return ans;
    }
};


int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends