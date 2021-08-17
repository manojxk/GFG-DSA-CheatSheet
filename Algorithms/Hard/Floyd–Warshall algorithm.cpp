/*
All pair shortes path
DP
Just like Dijkstra's algorithm, the Floyd Warshall algorithm is used to find the shortest path between all vertices in the weighted graph.
This algorithm works with both directed and undirected graphs but it does not work along with the graph with negative cycles.
We initialize the solution matrix same as the input graph matrix as a first step. Then we update the solution matrix by considering all vertices
 as an intermediate vertex.The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an
  intermediate vertex in the shortest path.

*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    vector<vector<int>> graph = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};

    int n = graph.size();
    vector<vector<int>> dist = graph;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
