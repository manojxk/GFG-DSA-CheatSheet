// https://practice.geeksforgeeks.org/problems/adding-array-element4756/1

int minOperations(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
    }

    int noOfOperations = 0;
    while (minheap.top() < k)
    {
        int first = minheap.top();
        minheap.pop();
        int second = minheap.top();
        minheap.pop();
        minheap.push(first + second);
        noOfOperations++;
    }
    return noOfOperations;
}
