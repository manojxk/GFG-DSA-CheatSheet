/*
DP
From a source vertex v, find the shortest distance to all other nodes in the graph
1.Initially d[v] = 0 and for all other elements d[] = inf
2.In each pass, relax all the edges.
  i.e. for edge (a,b) having weight w,
    d[b] = min(d[b], d[a] + w)
3.Assuming no negative edge cycle, since there are n vertices, shortest path
can only contain 'n-1' edges. Therefore we will get our answer in atmost n-1 passes.


What makes it better than dijkstra
Negative edges
It will work for -ve edges and -ve cycles
detect -ve cycle as well

*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int src;
    cin >> src;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}
//for -ve edge cycle check one more time if value changes then there is -ve cycle
