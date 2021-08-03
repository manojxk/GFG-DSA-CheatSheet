int findK(int matrix[MAX][MAX], int n, int m, int k)
{

    int T = 0;
    int B = n - 1;
    int L = 0;
    int R = m - 1;
    int d = 0;
    while (T <= B and L <= R)
    {
        if (d == 0)
        {
            for (int i = L; i <= R; i++)
            {

                k--;
                if (k == 0)
                {
                    return matrix[T][i];
                }
            }
            T++;
        }
        else if (d == 1)
        {
            for (int i = T; i <= B; i++)
            {

                k--;
                if (k == 0)
                {
                    return matrix[i][R];
                }
            }
            R--;
        }
        else if (d == 2)
        {
            for (int i = R; i >= L; i--)
            {

                k--;
                if (k == 0)
                {
                    return matrix[B][i];
                }
            }
            B--;
        }
        else if (d == 3)
        {
            for (int i = B; i >= T; i--)
            {

                k--;
                if (k == 0)
                {
                    return matrix[i][L];
                }
            }
            L++;
        }
        d = (d + 1) % 4;
    }
    return -1;
}
