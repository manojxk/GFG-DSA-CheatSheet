void printInorder(Node *root)
{
    list<int> result;
    stack<Node *> stack;
    Node *p = root;
    while (!stack.empty() || p != nullptr)
    {
        if (p != nullptr)
        {
            stack.push(p);
            p = p->left;
        }
        else
        {
            Node *node = stack.top();
            result.push_back(node->data); // Add after all left children
            stack.pop();
            p = node->right;
        }
    }
    for (auto i = result.begin(); i != result.end(); i++)
    {
        cout << *i << " ";
    }
}