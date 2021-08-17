#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int V, vector<vector<int>> adj, int visited[])
    {
        visited[V] = 1;
        for (int i = 0; i < adj[V].size(); i++)
        {
            if (!visited[adj[V][i]])
                dfs(adj[V][i], adj, visited);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> adj2(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j])
                {
                    adj2[i].push_back(j);
                }
            }
        }

        int visited[V] = {0};
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj2, visited);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
} // } Driver Code Ends