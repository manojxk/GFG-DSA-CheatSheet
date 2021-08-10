#include <bits/stdc++.h>
using namespace std;

void printMedians(double arr[], int n)
{
    //maxHeap
    priority_queue<double> lowerHalf;

    // min heap to store the greater half elements
    priority_queue<double, vector<double>, greater<double>> upperHalf;

    lowerHalf.push(arr[0]);

    double median[n];
    median[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        //insert
        double x = arr[i];
        if (lowerHalf.top() > x)
            lowerHalf.push(x);
        else
            upperHalf.push(x);
        //Balance
        int uH = upperHalf.size();
        int lH = lowerHalf.size();
        if (abs(uH - lH) >= 2)
        {
            if (upperHalf.size() > lowerHalf.size())
            {
                lowerHalf.push(upperHalf.top());
                upperHalf.pop();
            }
            else
            {
                upperHalf.push(lowerHalf.top());
                lowerHalf.pop();
            }
        }
        //Median
        uH = upperHalf.size();
        lH = lowerHalf.size();
        if (uH == lH)
        {
            median[i] = (upperHalf.top() + lowerHalf.top()) / 2;
        }
        else if (uH < lH)
        {
            median[i] = lowerHalf.top();
        }
        else
        {
            median[i] = upperHalf.top();
        }
    }
    for (int i = 0; i < n; i++)
        cout << median[i] << " ";
}

// Driver program to test above functions
int main()
{
    // stream of integers
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}
