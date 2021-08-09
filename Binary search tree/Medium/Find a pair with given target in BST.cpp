
void inorder(TreeNode *root, vector<int> &nums)
{
    if (root == nullptr)
        return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}
int Solution::t2Sum(TreeNode *A, int B)
{
    vector<int> nums;
    inorder(A, nums);
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        if ((nums[low] + nums[high]) == B)
        {
            return 1;
        }
        else if ((nums[low] + nums[high]) < B)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return 0;
}
