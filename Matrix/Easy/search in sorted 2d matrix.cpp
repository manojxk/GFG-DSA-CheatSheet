int matSearch(vector<vector<int>> &mat, int N, int M, int X)
{
    int l = 0, r = M - 1;

    while (l < N && r >= 0)
    {
        if (mat[l][r] == X)
        {
            return 1;
        }
        else if (mat[l][r] > X)
            r--;

        else
            l++;
    }

    return 0;
}