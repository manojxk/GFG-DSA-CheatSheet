vector<vector<int>> printGraph(int V, vector<int> adj[])
{
    vector<vector<int>> res(V);

    for (int i = 0; i < V; i++)
    {
        res[i].push_back(i);
        for (auto neigh : adj[i])
            res[i].push_back(neigh);
    }

    return res;
}