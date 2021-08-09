
Node *connect(Node *root)
{
    if (!root)
        return root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *x = q.front();
            q.pop();
            if (i < n)
            {
                x->next = q.front();
            }
            else
            {
                x->next = NULL;
            }
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
    }
    return root;
}
