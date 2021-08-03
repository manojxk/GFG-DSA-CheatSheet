#include <iostream>
#include <random>
using namespace std;
int main()
{
   int max=100, min=54,i;
   int range = max - min + 1;
   for (i=min; i<max;i++)
    {
        int num = rand() % range + min;
        cout<<num << " ";
    }
    return 0;
}