// https://practice.geeksforgeeks.org/problems/chinky-and-diamonds3340/1

int maxDiamonds(int a[], int n, int k)
{
    int maxsum = 0, front;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }
    while (k--)
    {
        front = pq.top();
        pq.pop();
        pq.push(front / 2);
        maxsum += front;
    }
    return maxsum;
}
