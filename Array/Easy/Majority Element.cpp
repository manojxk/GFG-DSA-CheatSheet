class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int cand = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                cand = num;
            }
            if (cand == num)
                count++;
            else
                count--;
        }
        return cand;
    }
};