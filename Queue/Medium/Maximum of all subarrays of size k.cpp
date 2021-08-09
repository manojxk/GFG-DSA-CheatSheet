#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[], int n, int k)
{
    vector<int> ans;
    list<int> l;

    if (k > n)
    {
        ans.push_back(*max_element(arr, arr + n));
        return ans;
    }
    int i = 0, j = 0;
    while (j < n)
    {
        //Calculations
        //Elements which are less than curr element are of no use
        while (!l.empty() and l.back() < arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            //ans from calculations
            ans.push_back(l.front());
            //Slide the window
            if (l.front() == arr[i])
                l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = solve(arr, 8, 3);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
