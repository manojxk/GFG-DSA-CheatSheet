// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
//https://youtu.be/g6OxU-hRGtY

int findLargestPower(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}

int countSetBits(int n)
{
    if (n <= 1)
        return n;
    int x = findLargestPower(n);
    return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x));
}
