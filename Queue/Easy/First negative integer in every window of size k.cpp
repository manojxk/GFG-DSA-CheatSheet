#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n, int k)
{
    list<int> l;
    int i = 0, j = 0;
    while (j < n)
    {
        if (a[j] < 0)
        {
            l.push_back(a[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (l.empty())
            {
                cout << 0 << " ";
            }
            else
            {
                cout << l.front() << " ";
                if (a[i] == l.front())
                    l.pop_front();
            }
            i++;
            j++;
        }
    }
}

int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    solve(arr,5,2);
}
