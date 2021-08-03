Node *findMin(Node *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
Node *inOrderSuccessor(Node *root, Node *x)
{
    //Case->1 has right subtree
    if (x->right != nullptr)
    {
        return findMin(x->right);
    }
    ////Case->2 has no right subtree
    else
    {
        Node *successor = nullptr;
        Node *ancestor = root;
        while (ancestor != x)
        {
            if (ancestor->data > x->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}