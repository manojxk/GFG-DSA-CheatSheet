void printPostorder(Node *root)
{
    list<int> result;
    stack<Node *> stack;
    Node *p = root;
    while (!stack.empty() || p != nullptr)
    {
        if (p != nullptr)
        {
            stack.push(p);
            result.push_front(p->data); // Reverse the process of preorder
            p = p->right;               // Reverse the process of preorder
        }
        else
        {
            Node *node = stack.top();
            stack.pop();
            p = node->left; // Reverse the process of preorder
        }
    }
    for (auto i = result.begin(); i != result.end(); i++)
    {
        cout << *i << " ";
    }
}