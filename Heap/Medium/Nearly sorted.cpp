#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;

    int index = 0;
    for (int i = 0; i < n; i++)
    {

        pq.push(arr[i]);
        if (pq.size() > k)
        {
            arr[index++] = pq.top();
            pq.pop();
        }
    }

    while (pq.empty() == false)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}
