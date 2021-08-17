
    bool isPossible(int arr[], int n, int m, int mx)
    {
        int student = 1;
        int sum = 0;
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
    int findPages(int arr[], int n, int m)
    {
        if (m > n)
            return -1;
        int start = *max_element(arr, arr + n);
        int end = accumulate(arr, arr + n, 0);
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
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
