class Solution 
{
    public:
	vector<int> res;
	void dfs(int V, vector<int> adj[], int visited[])
	{
	    res.push_back(V);
	    visited[V] = 1;
	    for(int i = 0; i < adj[V].size(); i++)
	    {
	        if(!visited[adj[V][i]])
	            dfs(adj[V][i], adj, visited);
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    int visited[V] = {0};
	    dfs(0,adj,visited);
	    return res;
	}
};