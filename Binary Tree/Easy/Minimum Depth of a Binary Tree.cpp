// Let me explain you why the return min(depth(root->left),depth(root->right)) + 1 won't work here ;

// You must be thinking like if you want to get the maximum depth of a tree i.e height of the tree then using max recursive call works therefore using min recursive call should also work here

// But you should pay attention that the if a node is having single child then calling for min for its left and right chill will always give you one because the null chill will give 0 and thus it would become the minimum value;

// in case it is a perfect binary tree,this min recursive technique will work quite perfectly but wont work otherwise only because of single child nodes

// The null child of a single child node doesn't disturbs the max recursive call which we use in calculating the height of the tree because 0 has nothing to do with max isn't it ?

// I hope you got it,thank you for giving me sometime !
// https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1

int minDepth(Node *root)
{
    if (root == nullptr)
        return INT_MAX;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

//O(n)

//  Level Order Traversal

int minDepth(Node *root)
{
    // Corner Case
    if (root == NULL)
        return 0;
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    while (q.empty() == false)
    {
        auto qi = q.front();
        q.pop();
        Node *node = qi.first;
        int depth = qi.second;
        if (node->left == NULL && node->right == NULL)
            return depth;
        if (node->left != NULL)
        {
            q.push({node->left, depth + 1});
        }
        if (node->right != NULL)
        {
            q.push(node->right, depth + 1);
        }
    }
}
