
void dfs(vector<vector<char>> &grid, int i, int j)
{
    //base case
    //if out of bounds or at a cell with '0' or '*', simply stop and return | end the dfs
    if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] != '1')
    {
        return;
    }
    // // destroying visited cells so they are not re-visited
    grid[i][j] = '*';
    // recursive dfs on all neighbours
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}
int numIslands(vector<vector<char>> &grid)
{
    int ans = 0; // number of groups
                 // iterating through given grid to find a '1'
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                ans++; // start a group and visit all members of this group using dfs
                dfs(grid, i, j);
            }
        }
    }
    return ans;
}
