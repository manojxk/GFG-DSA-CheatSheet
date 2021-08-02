// https://leetcode.com/problems/sum-of-two-integers/
//Iterative

int getSum(int a, int b)
{
    while (b != 0)
    {
        a = a ^ b;
        b = (a & b) << 1;
    }
    return a;
}

//Recursive
int getSum(int a, int b)
{
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1); //be careful about the terminating condition;
}