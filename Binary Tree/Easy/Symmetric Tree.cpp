#include <bits/stdc++.h>
using namespace std;

bool isMirror(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }

    if (root1 != nullptr && root2 != nullptr && root1->data == root2->data)
    {
        return isMirror(root1->right, root2->left) && isMirror(root1->left, root2->right);
    }

    return false;
}

bool isSymmetric(struct Node *root)
{
    return isMirror(root, root);
}

// Time Complexity: O(N)

// Auxiliary Space: O(h) where h is the maximum height of the tree 