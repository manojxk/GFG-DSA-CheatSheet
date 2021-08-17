#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, int i, int j, int &count1s)
{
    if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] != 1)
    {
        return;
    }
    grid[i][j] = 2;
    count1s++;
    dfs(grid, i, j + 1, count1s);
    dfs(grid, i + 1, j + 1, count1s);
    dfs(grid, i + 1, j, count1s);
    dfs(grid, i + 1, j - 1, count1s);
    dfs(grid, i, j - 1, count1s);
    dfs(grid, i - 1, j - 1, count1s);
    dfs(grid, i - 1, j, count1s);
    dfs(grid, i - 1, j + 1, count1s);
}

int findMaxArea(vector<vector<int>> &grid)
{
    int N = grid.size();
    int M = grid[0].size();
    int area = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 1)
            {
                int count1s = 0;

                dfs(grid, i, j, count1s);

                area = max(area, count1s);
            }
        }
    }

    return area;
}
