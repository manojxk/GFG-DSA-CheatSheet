// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution
{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> res;
        int profit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] < A[i + 1])
            {
                res.push_back({i, i + 1});
                profit = A[i + 1] - A[i];
            }
        }
        return res;
    }
};