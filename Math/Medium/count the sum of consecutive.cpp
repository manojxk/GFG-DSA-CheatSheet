// https://youtu.be/kKWV8T6SAvU
#include <bits/stdc++.h>
using namespace std;
/*
a+a+1+a+2 ... a+n-1 = N

(a+a+n-1)*n/2 = N
a = (2N-n^2+n)/2*n


start n = 2 and while rhs is positive



*/
long int countConsecutive(long int N)
{
    long int count = 0, n = 2;
    long int a = 0;
    while ((2 * N - pow(n, 2) + n) > 0)
    {
        a = (2 * N - pow(n, 2) + n) / (2 * n);
        int x = 2 * N - pow(n, 2) + n;

        if (x % (2 * n) == 0)
        {
            count++;
        }
        n++;
    }
    return count;
}

// Driver Code
int main()
{
    long int N = 15;
    cout << countConsecutive(N) << endl;
    // N = 10;
    // cout << countConsecutive(N) << endl;
    return 0;
}
