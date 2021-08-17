/*
1.Mark the current node as visited and also mark the index in recursion stack
2.Find all vertices which are not visited and adjacent to the current node
3.if the adjacent are already marked in the recursion stack then a cycle is found.

*/

#include <bits/stdc++.h>
using namespace std;
bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &stack)
{
    stack[src] = true;

    visited[src] = true;
    for (auto i : adj[src])
    {
        if (!visited[i] and iscycle(i, adj, visited, stack))
        {
            return true;
        }
        if (stack[i])
            return true;
    }

    stack[src] = false;
    return false;
}
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    vector<bool> stack(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and iscycle(i, adj, visited, stack))
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "Cycle";
    }
    else
    {
        cout << "No Cycle";
    }
}