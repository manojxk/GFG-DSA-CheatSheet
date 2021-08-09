#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() >= 2)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (M[i][j] == 1) //if i  know j then i is not celebrity
        {
            s.push(j);
        }
        else
        { //if i doesn't know j then j is not celebrity
            s.push(i);
        }
    }
    int potential_candidate = s.top();
    for (int i = 0; i < n; i++)
    {
        if (i != potential_candidate)
        {
            if (M[i][potential_candidate] == 0 or M[potential_candidate][i] == 1)
                return -1;
        }
    }
    return potential_candidate;
}
