int isBSTUtil(node *node, int min, int max)
{

    if (node == nullptr)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

int isBST(node *node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}
