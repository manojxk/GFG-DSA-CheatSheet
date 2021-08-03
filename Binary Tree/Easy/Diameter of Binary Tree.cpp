int height(Node *root)
{

    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(Node *root)
{
    if (root == nullptr)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max({ldiameter, rdiameter, lheight + rheight + 1});
}