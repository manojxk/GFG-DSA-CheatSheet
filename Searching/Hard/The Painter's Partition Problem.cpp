
bool isPossible(int arr[], int n, int m, long long mx)
{
    int student = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mx)
        {
            student++;
            sum = arr[i];
        }
        if (student > m)
            return false;
    }
    return true;
}
long long minTime(int arr[], int n, int m)
{
    if (m > n)
        return -1;
    long long start = *max_element(arr, arr + n);
    long long end = accumulate(arr, arr + n, 0);
    long long ans = -1;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
