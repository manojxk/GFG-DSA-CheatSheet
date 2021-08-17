
#include <bits/stdc++.h>
using namespace std;
static int t[101][101];
bool isPalindrome(string s, int i, int j)
{
    while(i < j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int minPalPartion(string p, int i, int j)
{
    if (i >= j or isPalindrome(p, i, j))
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    if(t[i][j] != -1){
        return t[i][j];
    }

    for (k = i; k < j; k++)
    {
        count = minPalPartion(p, i, k) + minPalPartion(p, k + 1, j) + 1;

        if (count < min)
            min = count;
    }

    return t[i][j] = min;
}

// Driver Code
int main()
{
    memset(t,-1,sizeof(t));
    string str = "nitin";

    cout << "Min cuts needed is "
         << minPalPartion(str, 0, str.size() - 1);
}
