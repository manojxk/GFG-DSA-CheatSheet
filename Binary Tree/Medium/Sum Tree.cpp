
int TREEsum(Node *node)
{
    if (node == nullptr)
        return 0;
    return TREEsum(node->left) + node->data + TREEsum(node->right);
}
bool isSumTree(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;

    int Lsum = TREEsum(root->left);
    int Rsum = TREEsum(root->right);

    if (root->data == (Lsum + Rsum) && isSumTree(root->left) && isSumTree(root->right))
        return true;
    return false;
}
