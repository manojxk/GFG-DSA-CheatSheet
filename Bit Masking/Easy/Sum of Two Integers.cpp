// https://leetcode.com/problems/sum-of-two-integers/
//Iterative

int getSum(int a, int b)
{
    unsigned int c = 0;
    while (b != 0)
    {
        c = (a & b);
        a = a ^ b;
        b = c << 1;
    }
    return a;
}

//Recursive
int getSum(int a, int b)
{
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1); //be careful about the terminating condition;
}