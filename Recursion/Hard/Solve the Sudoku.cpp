#include <bits/stdc++.h>
using namespace std;

// N is the size of the 2D matrix N*N
#define N 9

/* A utility function to print grid */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isValid(int grid[N][N], int x, int y, int val)
{
    for (int j = 0; j < N; j++)
    {
        if (grid[x][j] == val)
        {
            return false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (grid[i][y] == val)
        {
            return false;
        }
    }
    int smi = x / 3 * 3;
    int smj = y / 3 * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[smi + i][smj + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}
void solveSuduko(int grid[N][N], int i, int j)
{
    if (i == N)
    {
        print(grid);
        return;
    }
    int ni = 0;
    int nj = 0;
    if (j == N - 1)
    {
        ni = i + 1;
        nj = 0;
    }
    else
    {
        ni = i;
        nj = j + 1;
    }

    if (grid[i][j] != 0)
    {
        solveSuduko(grid, ni, nj);
    }
    else
    {
        for (int po = 1; po <= 9; po++)
        {
            if (isValid(grid, i, j, po))
            {
                grid[i][j] = po;
                solveSuduko(grid, ni, nj);
                grid[i][j] = 0;
            }
        }
    }
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 9},
                      {0, 0, 9, 0, 0, 0, 0, 0, 1},
                      {5, 0, 0, 0, 0, 4, 0, 0, 0},
                      {0, 0, 0, 8, 3, 0, 1, 0, 0},
                      {0, 1, 0, 7, 0, 0, 3, 0, 0},
                      {7, 0, 0, 0, 9, 6, 0, 0, 0},
                      {0, 6, 0, 0, 7, 0, 4, 0, 0},
                      {3, 7, 0, 5, 0, 0, 0, 0, 8},
                      {0, 8, 0, 0, 0, 0, 0, 6, 0}};

    solveSuduko(grid, 0, 0);
}
/*
Time complexity: O(9^(n*n)). 
For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). The time complexity remains the same but there will be some early 
pruning so the time taken will be much less than the naive algorithm but the upper bound time complexity remains the same.
*/