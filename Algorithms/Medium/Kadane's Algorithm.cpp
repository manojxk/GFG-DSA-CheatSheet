// C++ program to print largest contiguous array sum
#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n)
{
	int ans = INT_MIN;
    int msf = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        msf = max(a[i], msf + a[i]);
        ans = max(ans,msf);
    }
    return ans;
    
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
