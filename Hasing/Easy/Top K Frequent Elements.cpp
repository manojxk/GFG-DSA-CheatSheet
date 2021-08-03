class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m; //Key->Number...Value->Freq
        //STEP-1: Store frequency of all elements in map
        for (int ele : nums)
            m[ele] += 1;

        //STEP-2: Now build a heap
        priority_queue<pair<int, int>> heap; //Compare defines a max-heap based on frequency
        for (auto it : m)
            heap.push({it.second, it.first}); // n

        vector<int> ans; //Stores top-K elements
        //STEP-3: Pop top-k elemnts and store the numbers in ans vector
        while (k--)
        {
            auto temp = heap.top();
            heap.pop();
            ans.push_back(temp.second);
        } // klogn
        return ans;
    }
};