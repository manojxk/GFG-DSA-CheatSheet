class Solution
{
    void towerOfHanoi(int N, int from, int to, int aux, long long &moves)
    {
        if (N == 1)
        {
            cout << "move disk 1 from rod " << from << " to rod " << to << endl;

            moves++;

            return;
        }

        towerOfHanoi(N - 1, from, aux, to, moves);

        moves++;

        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;

        towerOfHanoi(N - 1, aux, to, from, moves);
    }

public:
    long long toh(int N, int from, int to, int aux)
    {
        long long moves = 0;

        towerOfHanoi(N, from, to, aux, moves);

        return moves;
    }
};