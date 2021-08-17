void dfs(int src, vector<bool> &vis, vector<int> adj[])
{
    vis[src] = true;
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (vis[adj[src][i]] == false)
            dfs(adj[src][i], vis, adj);
    }
}

int findMother(int n, vector<int> adj[])
{
    int mother = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i, vis, adj);
            mother = i;
        }
    }

    vector<bool> visited(n, false);
    dfs(mother, visited, adj);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            mother = -1;
    }
    return mother;
}