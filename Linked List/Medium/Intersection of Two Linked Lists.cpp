Node *findIntersection(Node *head1, Node *head2)
{
    unordered_set<int> s;

    while (head2 != NULL)
    {
        s.insert(head2->data);
        head2 = head2->next;
    }

    Node *start = NULL, *end = NULL;

    while (head1 != NULL)
    {
        if (s.find(head1->data) != s.end())
        {
            if (start == NULL)
            {
                start = end = head1;
            }
            else
            {
                end->next = head1;
                end = head1;
            }
        }

        head1 = head1->next;
    }

    if (start != NULL)
    {
        end->next = NULL;
    }

    return start;
}