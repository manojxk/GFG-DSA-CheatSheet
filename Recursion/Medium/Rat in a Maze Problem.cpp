#include <bits/stdc++.h>
using namespace std;

vector<string> res;
void findPathHelper(int i, int j, vector<vector<int>> &m, int n, string s)
{
    if (i < 0 or i >= n or j < 0 or j >= n or m[i][j] == 0)
    {
        return;
    }
    else if (i == n - 1 and j == n - 1)
    {
        res.push_back(s);
        return;
    }
    else
    {
        m[i][j] = 0;
        findPathHelper(i + 1, j, m, n, s + "D"); //D this order bcz we want sorted ans
        findPathHelper(i, j - 1, m, n, s + "L"); //L
        findPathHelper(i, j + 1, m, n, s + "R"); //R
        findPathHelper(i - 1, j, m, n, s + "U"); //U
        m[i][j] = 1;
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    string s = "";
    findPathHelper(0, 0, m, n, s);
    return res;
}
