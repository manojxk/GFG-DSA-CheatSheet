
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    
    int n1 = m - l + 1;
    int n2 = r - m;
    int arrL[n1], arrR[n2];
    for (int i = 0; i < n1; i++)
    {
        arrL[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arrR[i] = arr[i + m + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (arrL[i] <= arrR[j])
        {
            arr[k++] = arrL[i++];
        }
        else
        {
            arr[k++] = arrR[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = arrL[i++];
    }
    while (j < n2)
    {
        arr[k++] = arrR[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    else
        return;
}
