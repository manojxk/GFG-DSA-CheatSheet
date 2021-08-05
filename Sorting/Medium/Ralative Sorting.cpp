// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
{
    vector<int> ans;
    map<int, int> mp_A1;
    for (int x : A1)
    {
        mp_A1[x]++;
    }
    for (int x : A2)
    {
        if (mp_A1.find(x) != mp_A1.end())
        {
            for (int i = 0; i < mp_A1[x]; i++)
            {
                ans.push_back(x);
            }
            mp_A1.erase(x);
        }
    }

    for (auto ele : mp_A1)
    {
        for (int i = 0; i < ele.second; i++)
        {
            ans.push_back(ele.first);
        }
    }
}