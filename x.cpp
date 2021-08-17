/*
"""
Given a string s consisting of items as "*" and closed compartments as an open and close "|", an array of starting indices startIndices, and an array of ending indices endIndices, determine the number of items in closed compartments within the substring between the two indices, inclusive.

An item is represented as an asterisk *
A compartment is represented as a pair of pipes | that may or may not have items between them.
Example: 

     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
s = '| * * | * | * | * * *  *  *  |  *   |'

startIndices = [0,0,3,7]
endIndices = [4,5,7,13]

output: [2,3,2,5]

Improve your algorithm for multiple requests where input is an array of startIndices and endIndices

Approach: 
Traverse array for every element: x
 startIdx = startIndices[x]
 endIdx = endIndices[x]
 for(int i = startIdx; i <= endIdx; i++)
 {
  
  if(s[i] == '|')
  {
   pipe++;
   if(pipe >= 2)
   {
    res += count;
   }
  }
  else if(s[i] == '*')
  {
    count++;
  }
  
 }
 vectorr[x] = res;
 res = 0;
 



"""
*/



































#include <bits/stdc++.h>
using namespace std;
/*
     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
s = '| * * | * | * | * * *  *  *  |  *   |'
*/
vector<int> solve(string s, vector<int> startIndices, vector<int> endIndices, int n)
{
    vector<int> sol(n);
    for (int x = 0; x < n; x++)
    {
        int startIdx = startIndices[x];
        int endIdx = endIndices[x];
        int pipe = 0, res = 0, count = 0;
        for (int i = startIdx; i <= endIdx; i++)
        {

            if (s[i] == '|')
            {
                pipe++;
                if (pipe >= 2)
                {
                    res += count;
                    count = 0;
                }
            }
            else if (s[i] == '*')
            {
                count++;
            }
        }
        sol[x] = res;
        res = 0;
        pipe = 0;
        count = 0;
    }
    return sol;
}
int main()
{
    string s = "|**|*|*|*****|*|";
    vector<int> res = solve(s, {0, 0, 3, 7}, {4, 5, 7, 13}, 4);
    for (int x : res)
    {
        cout << x << " ";
    }
}