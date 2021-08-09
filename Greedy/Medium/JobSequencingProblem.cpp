#include <iostream>
#include <algorithm>
using namespace std;

class Job
{
public:
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);
    int max_deadline = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        max_deadline = max(max_deadline, arr[i].dead);
    }

    int slot[max_deadline + 1];

    for (int i = 0; i < n; i++)
    {
        slot[i] = -1;
    }
    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    cout << jobProfit << " " << countJobs;
    cout << endl;
    for (int i = 1; i <= max_deadline; i++)
    {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }
}

// Driver code
int main()
{
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";

    // Function call
    printJobScheduling(arr, n);
    return 0;
}
