

#include <bits/stdc++.h>
using namespace std;

void topoSortUtil(int V, vector<vector<int>> adj, vector<bool> &visited, vector<int> &res)
{

    visited[V] = true;
    for (int neighbour : adj[V])
    {
        if (!visited[neighbour])
            topoSortUtil(neighbour, adj, visited, res);
    }
    res.push_back(V);
}
vector<int> topoSort(int V, vector<vector<int>> adj)
{
    vector<int> res;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topoSortUtil(i, adj, visited, res);
    }
    reverse(res.begin(), res.end());
    return res;
}

string findOrder(string dict[], int N, int K)
{
    vector<vector<int>> g(K);
    for (int i = 0; i < N - 1; i++)
    {
        string w1 = dict[i];
        string w2 = dict[i + 1];

        for (int j = 0; j < min(w1.size(), w2.size()); j++)
        {
            if (w1[j] != w2[j])
            {
                g[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }
    vector<int> res = topoSort(K, g);
    string ans = "";
    for (int i : res)
        ans += i + 'a';

    return ans;
}
