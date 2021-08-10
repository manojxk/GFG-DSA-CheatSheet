Node *head = nullptr;
Node *prev = nullptr;
void bToDLLHelper(Node *root)
{
    if (root == nullptr)
        return;
    bToDLLHelper(root->left);
    if (prev == nullptr)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    bToDLLHelper(root->right);
}
Node *bToDLL(Node *root)
{
    bToDLLHelper(root);
    return head;
}