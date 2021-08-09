TreeNode *to_BST(vector<int> &nums, int l, int h)
{
    if (l > h)
        return nullptr;
    int m = (l + h) / 2;
    TreeNode *root = new TreeNode(nums[m]);
    root->left = to_BST(nums, l, m - 1);
    root->right = to_BST(nums, m + 1, h);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int l = 0;
    int h = nums.size() - 1;
    return to_BST(nums, l, h);
}