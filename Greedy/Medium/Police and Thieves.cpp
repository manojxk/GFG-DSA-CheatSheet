#include <bits/stdc++.h>
using namespace std;

int catchThieves(char arr[], int n, int k)
{
    vector<int> thieves, police;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'T')
        {
            thieves.push_back(i);
        }
        else
        {
            police.push_back(i);
        }
    }
    int count = 0;
    int i = 0, j = 0;
    while (i < police.size() && j < thieves.size())
    {
        int police_idx = police[i];
        int thieves_idx = thieves[j];
        int diff = abs(police_idx - thieves_idx);
        if (diff > k)
        {
            if (police_idx < thieves_idx)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        else
        {
            i++;
            j++;
            count++;
        }
    }
    return count;
}
