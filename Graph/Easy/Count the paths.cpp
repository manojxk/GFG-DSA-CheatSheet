void Graph::allPath(int s, int d, string psf)
{
    //if source equals to destination means we have path
    if (s == d)
    {
        cout << psf << endl;
        return;
    }
    visited[s] = true;
    //check if we have path from neighbours to destination
    for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
    {
        if (visited[*i] == false)
        {
            allPath(*i, d, psf + to_string(*i));
        }
    }
    //use this in other path
    visited[s] = false;
}