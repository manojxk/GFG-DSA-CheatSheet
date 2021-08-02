#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> minheap(arr, arr + n);
    long long cost = 0;
    while (minheap.size() >= 2)
    {
        long long element1 = minheap.top();
        minheap.pop();

        long long element2 = minheap.top();
        minheap.pop();

        cost += element1 + element2;
        minheap.push(element1 + element2);
    }
    return cost;
}
