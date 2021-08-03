// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
#include <bits/stdc++.h>
using namespace std;
int MissingNumber(vector<int> &array)
{
    int total = 0;
    for (int i = 0; i < array.size(); i++)
    {
        total += i + 1;
        total -= array[i];
    }
    total += array.size() + 1;
    return total;
    // Your code goes here
}
int main()
{
    int arr[] = {1, 2, 3, 5};
    cout << MissingNumber(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}

int MissingNumberXor(vector<int> &array)
{
    int total = 0;
    int arr = 0;
    for (int i = 0; i < array.size(); i++)
    {
        total ^= (i + 1);
        arr ^= array[i];
    }
    total ^= (array.size() + 1);
    return arr ^ total;
    // Your code goes here
}