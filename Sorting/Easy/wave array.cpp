// https://www.geeksforgeeks.org/sort-array-wave-form-2/

// This function sorts arr[0..n-1] in wave form, i.e.,
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5]..
void sortInWave(int arr[], int n)
{
    // Sort the input array
    sort(arr, arr + n);

    // Swap adjacent elements
    for (int i = 0; i < n - 1; i += 2)
        swap(&arr[i], &arr[i + 1]);
}

void sortInWave(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i += 2)
    {
        // If current even element is smaller than previous
        if (i > 0 && arr[i] < arr[i - 1])
            swap(&arr[i], &arr[i - 1]);

        // If current even element is smaller than next
        if (i < n - 1 && arr[i] < arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    }
}