class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr or head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow and fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast == NULL or fast->next == NULL)
            return nullptr;
        fast = head;
        while (fast->next != slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = nullptr;
        return head;
    }
};