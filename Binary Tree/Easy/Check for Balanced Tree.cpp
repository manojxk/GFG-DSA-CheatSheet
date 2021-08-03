// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

int height(Node *root)
{

    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(Node *root)
{
    if (root == nullptr)
    {
        return 1;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 and isBalanced(root->left) and isBalanced(root->right))
        return 1;

    return 0;
}