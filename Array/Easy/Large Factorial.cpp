class Solution
{
    void findFact(vector<ll> &fact, ll maxVal)
    {
        fact[0] = fact[1] = 1;

        for (ll i = 2; i <= maxVal; i++)
        {
            fact[i] = (i * fact[i - 1]) % 1000000007;
        }
    }

public:
    vector<ll> factorial(vector<ll> arr, int n)
    {
        ll maxVal = *max_element(arr.begin(), arr.end());

        vector<ll> fact(maxVal + 1);
        findFact(fact, maxVal);

        vector<ll> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = fact[arr[i]];
        }

        return res;
    }
};