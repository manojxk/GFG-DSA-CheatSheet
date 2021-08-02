ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy_head = new ListNode(0);
    ListNode *curr = dummy_head;

    while (l1 and l2)
    {
        if (l1->val < l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
    }
    curr->next = l1 ? l1 : l2;
    return dummy_head->next;
}

Node *merge(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}