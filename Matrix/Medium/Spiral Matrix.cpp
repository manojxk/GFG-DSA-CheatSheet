class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int T = 0;
        int B = matrix.size() - 1;
        int L = 0;
        int R = matrix[0].size() - 1;
        int d = 0;
        while (T <= B and L <= R)
        {
            if (d == 0)
            {
                for (int i = L; i <= R; i++)
                {
                    ans.push_back(matrix[T][i]);
                }
                T++;
            }
            else if (d == 1)
            {
                for (int i = T; i <= B; i++)
                {
                    ans.push_back(matrix[i][R]);
                }
                R--;
            }
            else if (d == 2)
            {
                for (int i = R; i >= L; i--)
                {
                    ans.push_back(matrix[B][i]);
                }
                B--;
            }
            else if (d == 3)
            {
                for (int i = B; i >= T; i--)
                {
                    ans.push_back(matrix[i][L]);
                }
                L++;
            }
            d = (d + 1) % 4;
        }
        return ans;
    }
};
/*
     L       R
 T   1,  2,  3
    
     4,  5,  6
    
 B   7,  8,  9


*/