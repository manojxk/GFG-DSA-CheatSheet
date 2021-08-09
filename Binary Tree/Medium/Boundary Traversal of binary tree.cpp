void LeftTree(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (root->left)
    {
        v.push_back(root->data);
        LeftTree(root->left, v);
    }
    else if (root->right)
    {
        v.push_back(root->data);
        LeftTree(root->right, v);
    }
}

void Leaf(Node *root, vector<int> &v)
{
    if (!root)
        return;
    Leaf(root->left, v);
    if (!root->left and !root->right)
        v.push_back(root->data);
    Leaf(root->right, v);
}

void RightTree(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (root->right)
    {
        RightTree(root->right, v);
        v.push_back(root->data);
    }
    else if (root->left)
    {
        RightTree(root->left, v);
        v.push_back(root->data);
    }
}
vector<int> printBoundary(Node *root)
{
    //Your code here
    vector<int> v;
    if (!root)
        return v;
    v.push_back(root->data);
    LeftTree(root->left, v);
    Leaf(root, v);
    RightTree(root->right, v);
    return v;
}