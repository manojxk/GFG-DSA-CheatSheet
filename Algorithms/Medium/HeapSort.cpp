
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;   // i -> parent node.
    int l = 2 * i + 1; //l-> left child of i.
    int r = 2 * i + 2; //r -> right child of i.

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); //Here the root is passed as largest.
    }
}

//Function to build a Heap from array.
void buildHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
}

//Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
