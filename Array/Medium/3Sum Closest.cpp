// https://practice.geeksforgeeks.org/problems/three-sum-closest/1/#

int threeSumClosest(vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(target - sum) < abs(target - ans))
            {
                ans = sum;
            }
            if (abs(target - sum) == abs(target - ans))
            {
                ans = max(sum, ans);
            }
            if (sum > target)
                r--;
            else
                l++;
        }
    }
    return ans;
}
