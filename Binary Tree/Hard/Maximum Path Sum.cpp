
#include <bits/stdc++.h>
using namespace std;

int maxPathSumUtil(Node *root, int &ans)
{
    //Base Case
    if (root == nullptr)
        return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max({root->data, root->data + left + right, root->data + left, root->data + right});

    int ans = max(ans, nodeMax);
    int singlePathsum = max({root->data, root->data + left, root->data + right});
    return singlePathsum;
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}
