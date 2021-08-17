/* Dynamic Programming implementation of MCP problem */
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int i, j;
    int t[r][c];

    t[0][0] = grid[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i < r; i++)
        t[i][0] = t[i - 1][0] + grid[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j < c; j++)
        t[0][j] = t[0][j - 1] + grid[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i < r; i++)
        for (j = 1; j < c; j++)
            t[i][j] = min({t[i - 1][j - 1],
                           t[i - 1][j],
                           t[i][j - 1]}) +
                      grid[i][j];

    return t[r - 1][c - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3},
                                {4, 8, 2},
                                {1, 5, 3}};
    cout << " " << minCost(grid);
    return 0;
}
