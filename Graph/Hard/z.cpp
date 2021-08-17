/*
optimize box weight
Given list of integers, partition it into 2 subsets s1 and s2 such that sum of s1 is greater than that of s2. Also the number of elements in s1 should be minimal.
Return s1 in increasing order.
Notice if more than one subset A exists, return one with max sum

input:
1. nums[4,5,2,3,1,2]
output=[4,5]
2. nums=[10,5,3,1,20]
output:20
3. nums=[1,2,3,5,8]
output:[5,8]
4. nums = [10]
output: [10]

Approach:
step 1: Calculate total sum 
step 2: weight(s1) > sum/2 + 1
step 3: Use heap to get maximum element and add till step 2 condition is not fullfilled.




*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
vector<int> solve(vector<int> v)
{
    vector<int> ans;
    int sum = accumulate(v.begin(), v.end(), 0);
    int req_wt = sum / 2 + 1;
    int curr_wt = 0;
    priority_queue<int> pq(v.begin(), v.end());
    while (curr_wt < req_wt)
    {
        curr_wt += pq.top();
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> v = {10};
    vector<int> res = solve(v);
    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}
































/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Example 4:

Input: nums = [1]
Output: [1]


Approach:
case 1: Next permutation is not possible 
reverse the array

case2: Next permutation is possible
1 2 3 


7 6 5

1 2 7 6 5

1 5 2 6 7

1 1 5
step1: traverse from end till we get a smaller number less than last value;
step2: swap last no. with smaller number which we got in 1st step
step3: sort the half which is after smaller no(from step 1)

# https://leetcode.com/problems/next-permutation/

*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solve(vector<int> v)
{
    //case 1
    int n = v.size();

    int i = 0;

    for (i = 0; i < n - 1; i++)
    {
        if (v[i] < v[i + 1])
            break;
    }
    if (i == n - 1)
    {
        reverse(v.begin(), v.end());
        return v;
    }
    int k = 0;
    for (k = n - 1; k > 0; k--)
    {
        int last = v[k];
        for (i = k - 1; i >= 0; i--)
        {
            if (v[i] < last)
            {
                swap(v[i], v[k]);
                sort(v.begin() + i + 1, v.end());
                return v;
            }
        }
    }
}

int main()
{
    vector<int> v = {2, 3, 1};
    vector<int> res = solve(v);
    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}
*/
//[2,3,1]
//3 1 2



