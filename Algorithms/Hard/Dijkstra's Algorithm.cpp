/*
From a source vertex v, find the shortest distance to all other nodes in the graph
1.Initially d[v] = 0 and for all other elements d[] = inf
2.While set is not empty
 A. Pick a vertex u from set s that has minimum distance value
 B. Update distance value of all adjancent vertices of u.

Doesn't handle negative cycle
Work on directed and undirected
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    int src;
    cin >> src;
    vector<int> dist(n, INF);
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto i : graph[x.second])
        {
            if (dist[i.first] > dist[x.second] + i.second)
            {
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}
//for -ve edge cycle check one more time if value changes then there is -ve cycle
