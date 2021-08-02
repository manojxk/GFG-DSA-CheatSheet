
ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr and fast->next != nullptr and fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head2 = reverseList(slow->next);

    while (head and head2)
    {
        if (head->val != head2->val)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
