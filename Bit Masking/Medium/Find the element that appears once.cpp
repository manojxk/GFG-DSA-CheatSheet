int search(int A[], int N)
{
    int res = 0;

    for (int i = 0; i < N; i++)
        res ^= A[i];

    return res;
}