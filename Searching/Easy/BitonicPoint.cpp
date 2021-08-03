#include <bits/stdc++.h>
using namespace std;

int bitconic(int arr[], int n)
{
	int l = 0, r = n - 1, mid;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
			return arr[mid];
		else if (arr[mid] > arr[mid + 1])
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return arr[mid];
}

