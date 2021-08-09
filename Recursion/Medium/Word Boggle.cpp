#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, int i, int j, string word, int ind)
{
    if (ind == word.size())
        return true;
    if (i >= board.size() || i < 0 || j < 0 || j >= board[0].size() || board[i][j] != word[ind])
        return false;
    board[i][j] = '*';
    bool result = dfs(board, i - 1, j, word, ind + 1) ||
                  dfs(board, i, j - 1, word, ind + 1) ||
                  dfs(board, i, j + 1, word, ind + 1) ||
                  dfs(board, i + 1, j, word, ind + 1);
    board[i][j] = word[ind];
    return result;
}
bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (dfs(board, i, j, word, 0))
                return true;
        }
    }
    return false;
}
