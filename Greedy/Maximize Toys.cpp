// https://practice.geeksforgeeks.org/problems/maximize-toys0331/1

int toyCount(int N, int K, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int sum = 0;
    int ans = 0;
    for (int toy : arr)
    {
        if (sum + toy <= K)
        {
            ans++;
            sum += toy;
        }
    }
    return ans;
}