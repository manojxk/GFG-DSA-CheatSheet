
vector<int> BoundaryElements(vector<vector<int>> &m)
{
    int n = m.size();
    vector<int> res;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                res.push_back(m[i][j]);
        }
    }
    return res;
}
