vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> res;
    int visited[V] = {0};
    visited[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        res.push_back(current);
        for (int neighbour : adj[current])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
    return res;
}