// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
    bool isPossible(int n, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        for (auto edges : prerequisites)
        {
            int to = edges.first;
            int from = edges.second;
            adj[from].push_back(to);
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
            return false;
        }
        return false;
    }
};


int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
