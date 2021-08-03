#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll arr[], ll low, ll mid, ll high)
{
    ll n1 = mid - low + 1;
    ll n2 = high - mid;

    ll right[n1], left[n2];

    for (ll i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }

    for (ll i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    ll i = 0, j = 0, k = low;
    ll res = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }

    return res;
}

ll mergeSort(ll arr[], ll low, ll high)
{
    ll res = 0;

    if (low < high)
    {
        ll mid = low + (high - low) / 2;

        res += mergeSort(arr, low, mid);
        res += mergeSort(arr, mid + 1, high);

        res += merge(arr, low, mid, high);
    }

    return res;
}

ll inversionCount(ll arr[], ll N)
{
    return mergeSort(arr, 0, N - 1);
}
