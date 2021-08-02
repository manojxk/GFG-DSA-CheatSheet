// https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1

int maxConsecutiveOnes(int N)
{
    int count = 0, ans = 0;
    while (N)
    {
        int x = N & 1;
        N >>= 1;
        if (x == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        ans = max(ans, count);
    }
    return ans;
}