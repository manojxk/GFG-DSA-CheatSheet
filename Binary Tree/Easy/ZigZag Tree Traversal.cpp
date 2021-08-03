/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        int level = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, level});
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 1; i <= n; i++)
            {
                TreeNode *curr = q.front().first;
                level = q.front().second;
                q.pop();
                temp.push_back(curr->val);
                if (curr->left != nullptr)
                    q.push({curr->left, level + 1});
                if (curr->right != nullptr)
                    q.push({curr->right, level + 1});
            }
            if (level & 1)
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            else
                ans.push_back(temp);
        }
        return ans;
    }
};