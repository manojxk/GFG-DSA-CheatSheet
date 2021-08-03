// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{

    vector<int> pos;
    vector<int> neg;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    i = 0;
    j = 0;
    k = 0;
    while (i < pos.size() and j < neg.size())
    {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (j < neg.size())
    {
        arr[k++] = neg[j++];
    }
    while (i < pos.size())
    {
        arr[k++] = pos[i++];
    }
}
