Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->data <= b->data)
    {
        a->bottom = merge(a->bottom, b);
        return a;
    }
    else
    {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}
Node *flatten(Node *root)
{
    if (!root)
        return root;
    if (!root->next)
        return root;
    Node *x = root->next->next;
    Node *temp = merge(root, root->next);
    temp->next = x;
    return flatten(temp);
}