#include <bits/stdc++.h>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n)
{
    // code here
    vector<int> res;
    for (int i = 1; i < k; i++)
    {
        res.push_back(-1);
    }
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {

        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            minheap.pop();
        }
        if (minheap.size() == k)
        {
            res.push_back(minheap.top());
        }
    }

    return res;
}
