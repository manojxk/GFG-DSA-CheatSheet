unsigned int reverse(unsigned int A)
{
    unsigned int B = 0; //B will hold the reversed number
    for (int i = 0; i < 32; i++)
    {                  //Iterating on all bit positions
        int k = A & 1; //Extracting the rightmost bit from A (the ith bit in original number)
        B <<= 1;       //Shifting B to left (rightmost bit becomes 0)
        B |= k;        //Adding the extracted bit
        A >>= 1;       //Now the (i+1)st bit shifts to the rightmost position in A
    }
    return B;
}