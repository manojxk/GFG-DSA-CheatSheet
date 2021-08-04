class Solution
{
public:
    void insert(queue<int> &q, int k)
    {
        q.push(k);
    }

    int findFrequency(queue<int> &q, int k)
    {
        int ans = 0;
        int s = q.size();
        while (s--)
        {
            if (q.front() == k)
                ans++;
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};