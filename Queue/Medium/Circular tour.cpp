#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    //Your code here
    int start = 0, deficit = 0;
    int capacity = 0;

    for (int i = 0; i < n; i++)
    {
        capacity += p[i].petrol - p[i].distance;
        if (capacity < 0)
        {
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
}