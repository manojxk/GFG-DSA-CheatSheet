void printPreorder(Node *root)
{
    list<int> result;
    stack<Node *> stack;
    Node *p = root;
    while (!stack.empty() || p != nullptr)
    {
        if (p != nullptr)
        {
            stack.push(p);
            result.push_back(p->data); // Add before going to children
            p = p->left;
        }
        else
        {
            Node *node = stack.top();
            stack.pop();
            p = node->right;
        }
    }
    for (auto i = result.begin(); i != result.end(); i++)
    {
        cout << *i << " ";
    }
}