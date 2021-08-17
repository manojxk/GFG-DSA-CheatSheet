#include <bits/stdc++.h>
using namespace std;

bool check(int i, int j, int N, int M, vector<vector<int>> &hospital)
{
    if (i >= 0 and i < N and j >= 0 and j < M and hospital[i][j] == 1)
    {
        return true;
    }
    return false;
}

int helpaterp(vector<vector<int>> hospital)
{
    int N = hospital.size();
    int M = hospital[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (hospital[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int timer = -1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (check(x - 1, y, N, M, hospital))
            {
                q.push({x - 1, y});
                hospital[x - 1][y] = 2;
            }
            if (check(x+1, y, N, M, hospital))
            {
                q.push({x+1, y});
                hospital[x+1][y] = 2;
            }
            if (check(x, y-1, N, M, hospital))
            {
                q.push({x, y-1});
                hospital[x][y-1] = 2;
            }
            if (check(x, y+1, N, M, hospital))
            {
                q.push({x, y+1});
                hospital[x][y+1] = 2;
            }
        }

        timer++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (hospital[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return timer;
}
