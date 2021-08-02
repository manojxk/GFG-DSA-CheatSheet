void reverse()
{
    Node *current = head;
    Node *prev = nullptr, *next = nullptr;
    while (current != nullptr)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}