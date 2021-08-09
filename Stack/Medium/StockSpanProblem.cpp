#include <bits/stdc++.h>
using namespace std;

void printNG2L(int arr[], int n)
{
    stack<pair<int, int>> st;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            v.push_back(-1);
        }
        else if (st.top().first > arr[i])
        {
            v.push_back(st.top().second);
        }
        else if (st.top().first <= arr[i])
        {
            while (!st.empty() and st.top().first <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }





    for (int i = 0; i < n; i++)
    {
        v[i] = i - v[i];
    }

    for (int i : v)
        cout << i << " ";
}

int main()
{
    int arr[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNG2L(arr, n);
    return 0;
}
