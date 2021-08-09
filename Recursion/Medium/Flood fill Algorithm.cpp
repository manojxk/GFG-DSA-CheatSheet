

void floodFillUtil(vector<vector<int>> &screen, int x, int y, int m, int n, int prevC, int newC)
{
    if (x < 0 or x > m or y < 0 or y > n or screen[x][y] != prevC)
    {
        return;
    }
    screen[x][y] = newC;
    floodFillUtil(screen, x, y + 1, m, n, prevC, newC);
    floodFillUtil(screen, x, y - 1, m, n, prevC, newC);
    floodFillUtil(screen, x + 1, y, m, n, prevC, newC);
    floodFillUtil(screen, x - 1, y, m, n, prevC, newC);
}

void floodFill(vector<vector<int>> &screen, int x, int y, int newC)
{
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, screen.size(), screen[0].size(), prevC, newC);
}
