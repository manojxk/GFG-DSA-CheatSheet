#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *curr = head;
    Node *next = nullptr;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list->
    while (curr != nullptr)
    {
        next = curr->next;

        Node *copy = new Node(curr->val);
        curr->next = copy;
        copy->next = next;

        curr = next;
    }

    // Second round: assign random pointers for the copy nodes->
    curr = head;
    while (curr != nullptr)
    {
        if (curr->random != nullptr)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Third round: restore the original list, and extract the copy list->
    curr = head;
    Node *pseudoHead = new Node(0);
    Node *copy = nullptr;
    Node *copyIter = pseudoHead;

    while (curr != nullptr)
    {
        next = curr->next->next;

        // extract the copy
        copy = curr->next;
        copyIter->next = copy;
        copyIter = copy;

        // restore the original list
        curr->next = next;

        curr = next;
    }

    return pseudoHead->next;
}

int main()
{
}
