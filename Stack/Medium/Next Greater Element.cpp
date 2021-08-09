#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
    stack<int> st;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            v.push_back(-1);
        }
        else if (st.top() > arr[i])
        {
            v.push_back(st.top());
        }
        else if (st.top() <= arr[i])
        {
            while (!st.empty() and st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
