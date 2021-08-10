#include <bits/stdc++.h>
using namespace std;
#define n 4
void solve(bool board[n][n], int row, bool cols[], bool ndiag[], bool rdiag[])
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if ((cols[col] == false) && (ndiag[row + col] == false) && (rdiag[row - col + n - 1] == false))
        {
            board[row][col] = true;
            cols[col] = true;
            ndiag[row + col] = true;
            rdiag[row - col + n - 1] = true;
            solve(board, row + 1, cols, ndiag, rdiag);
            board[row][col] = false;
            cols[col] = false;
            ndiag[row + col] = false;
            rdiag[row - col + n - 1] = false;
        }
    }
}

void solveNQueens()
{
    bool board[n][n] = {false};
    bool cols[n] = {false};
    bool ndiag[2 * n - 1] = {false};
    bool rdiag[2 * n - 1] = {false};
    solve(board, 0, cols, ndiag, rdiag);
}

int main()
{
    solveNQueens();
    return 0;
}
