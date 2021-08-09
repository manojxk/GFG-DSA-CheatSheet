
int catchThieves(char arr[], int n, int k)
{
    // Code here
    stack<int> theives_idx;
    stack<int> police_idx;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 'T')
            theives_idx.push(i);
        else
            police_idx.push(i);
    }

    int ans = 0;
    int count = 0;

    while (!police_idx.empty() && !theives_idx.empty())
    {
        int p_idx = police_idx.top();
        int t_idx = theives_idx.top();

        int diff = abs(p_idx - t_idx);

        if (diff > k)
        {
            if (p_idx < t_idx)
                police_idx.pop();
            else
                theives_idx.pop();
        }
        else if (diff <= k)
        {
            police_idx.pop();
            theives_idx.pop();
            ans++;
        }
    }

    return ans;
}
