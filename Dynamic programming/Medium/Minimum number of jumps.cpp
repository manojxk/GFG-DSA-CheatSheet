
bool canJump(vector<int> &A)
{

    if (A.size() <= 1)
        return 1;
    if (A[0] == 0)
        return false;
    int ladder = A[0]; //keep track of largest ladder you have
    int stairs = A[0]; // keep track of stairs in the current ladder
    int jump = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (i == A.size() - 1)
            return jump;
        if (i + A[i] > ladder)
            ladder = i + A[i]; //build up the ladder
        stairs--;              //use up the stairs
        if (stairs == 0)
        {
            jump++;              //no stairs left, now jump
            stairs = ladder - i; //now get new set of stairs
            if (stairs == 0)
                return -1;
        }
    }
    return jump;
}
