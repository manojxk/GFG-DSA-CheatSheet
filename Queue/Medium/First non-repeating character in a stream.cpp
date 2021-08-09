
#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    string s = "";
    queue<char> q;
    int arr[26] = {0};
    for (int i = 0; i < A.size(); i++)
    {

        q.push(A[i]);
        arr[A[i] - 'a']++;
        while (!q.empty())
        {
            if (arr[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
                break;
        }
        if (q.empty())
            s += '#';
        else
            s += q.front();
    }

    return s;
}
