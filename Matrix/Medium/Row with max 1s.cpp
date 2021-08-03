class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        if (n == 0)
            return 0;

        int i = 0;
        int j = m - 1;
        int row = -1;

        while (i < n && j >= 0)
        {
            if (arr[i][j] == 1)
            {
                row = i;
                j--;
            }
            else
            {
                i++;
            }
        }
        return row;
    }
};